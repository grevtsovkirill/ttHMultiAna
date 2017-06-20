#ifndef TreeAssist_h
#define TreeAssist_h


#ifndef __CINT__
#include "TopEventSelectionTools/TreeManager.h"
#include <boost/scoped_ptr.hpp>
#include "AthContainers/DataVector.h"
#include <iostream>

class VectorWrapper {
  struct Concept {
    virtual ~Concept() {}
    virtual void push_to_stack() = 0;
    virtual void set_current_entry(int, const void*) = 0;
    virtual void* get_vector_ptr() = 0;
    virtual void clear() = 0;
  };
  template<typename U, typename V> struct Model : Concept {
    //    typedef U (*locfcntype)(const V &); 
    typedef std::function<U(const V&)> locfcntype;
    explicit Model(locfcntype fcn, top::TreeManager& tree, const char* brname): vector(new std::vector<U>()), fcn(fcn), index(0), instance(0), brname(brname), errored(false) { tree.makeOutputVariable(*vector, brname); }
    virtual void set_current_entry(int index, const void* instance) { this->index=index; this->instance=static_cast<const V*>(instance);}
    virtual void push_to_stack() { 
      // hrm hrm, default = 0 ?  Will do some template magic later if we need to store some non-numeric type
      U tmpvar(0);
      try {
	tmpvar = (fcn(*instance));
      } catch (const std::exception& e) {
	if (!errored) {
	  std::cout << "\n **** WARNING!!! Function to extract variable to be stored in " << brname << " threw exception, zero will be stored.  This is your only warning!\n";
	  std::cout <<e.what() << std::endl;
	  errored = true;
	}
      }
      vector->push_back(tmpvar); 
    }
    virtual void* get_vector_ptr() { return vector; }
    virtual void clear() { vector->clear(); }
  private:
    std::vector<U>* vector;
    const locfcntype fcn;
    int index;
    const V* instance;
    std::string brname;
    bool errored;
  };
  boost::scoped_ptr<Concept> object;
public:
  //  template<typename U, typename V> explicit VectorWrapper(U (*fcn)(const V &), top::TreeManager& tree, const char* brname) : object(new Model<U,V>(fcn, tree, brname)) {}
  template<typename U, typename V> explicit VectorWrapper(std::function<U(const V &)> fcn, top::TreeManager& tree, const char* brname) : object(new Model<U,V>(fcn, tree, brname)) {}
  void push_to_stack() { object->push_to_stack(); }
  void set_current_entry(int index, const void* instance) { object->set_current_entry(index, instance); }
  void* get_vector_ptr() { return object->get_vector_ptr(); }
  void clear() { object->clear(); }
};
class VectorWrapperCollection {
  std::vector<VectorWrapper*> vws;

public:
  VectorWrapperCollection() {}
  VectorWrapperCollection(std::vector<VectorWrapper*> wrappers) : vws(wrappers) {}
  template<typename T> void push_all(const DataVector<T>& invec) {
    for (std::vector<VectorWrapper*>::iterator vw=vws.begin();
         vw != vws.end(); ++vw) {
      (*vw)->clear();
      for (unsigned int idx = 0; idx < invec.size(); ++idx) {
        (*vw)->set_current_entry(idx, invec[idx]);
        (*vw)->push_to_stack();
      }
    }
  }

  template<typename T, typename Tref> void push_selected(const DataVector<T>& invec, std::function<bool(Tref)> selector) {
    for (std::vector<VectorWrapper*>::iterator vw=vws.begin();
         vw != vws.end(); ++vw) {
      (*vw)->clear();
      //std::cout<<"size in push_selected"<<invec.size()<<std::endl;
      for (unsigned int idx = 0; idx < invec.size(); ++idx) {
	if (selector( *(invec[idx]) )) {
	  (*vw)->set_current_entry(idx, invec[idx]);
	  (*vw)->push_to_stack();
	}
      }
    }
  }
};

class ScalarWrapper {
  struct Concept {
    virtual ~Concept() {}
    virtual void push() = 0;
    virtual void set_instance(const void*) = 0;
    virtual void* get_ptr() = 0;
    virtual void clear() = 0;
  };
  template<typename U, typename V> struct Model : Concept {
    //    typedef U (*locfcntype)(const V &); 
    typedef std::function<U(const V&)> locfcntype;
    explicit Model(locfcntype fcn, top::TreeManager& tree, const char* brname): ptr(new U), fcn(fcn), brname(brname), errored(false) { tree.makeOutputVariable(*ptr, brname); }
    virtual void set_instance(const void* instance) { this->instance=static_cast<const V*>(instance);}
    virtual void push() { 
      // hrm hrm, default = 0 ?  Will do some template magic later if we need to store some non-numeric type
      try {
	*ptr = (fcn(*instance));
      } catch (...) {
	if (!errored) {
	  std::cout << "\n **** WARNING!!! Function to extract variable to be stored in " << brname << " threw exception, zero will be stored.  This is your only warning!\n\n";
	  errored = true;
	}
      }
    }
    virtual void* get_ptr() { return ptr; }
    virtual void clear() { *ptr = 0; }
  private:
    U* ptr;
    const locfcntype fcn;
    const V* instance;
    std::string brname;
    bool errored;
  };
  boost::scoped_ptr<Concept> object;
public:
  //  template<typename U, typename V> explicit VectorWrapper(U (*fcn)(const V &), top::TreeManager& tree, const char* brname) : object(new Model<U,V>(fcn, tree, brname)) {}
  template<typename U, typename V> explicit ScalarWrapper(std::function<U(const V &)> fcn, top::TreeManager& tree, const char* brname) : object(new Model<U,V>(fcn, tree, brname)) {}
  void push() { object->push(); }
  void set_instance(const void* instance) { object->set_instance(instance); }
  void* get_ptr() { return object->get_ptr(); }
  void clear() { object->clear(); }
};
class ScalarWrapperCollection {
  std::vector<ScalarWrapper*> sws;

public:
  ScalarWrapperCollection() {}
  ScalarWrapperCollection(std::vector<ScalarWrapper*> wrappers) : sws(wrappers) {}
  template<typename T> void push_all(const T& event) {
    for (std::vector<ScalarWrapper*>::iterator sw=sws.begin();
         sw != sws.end(); ++sw) {
      (*sw)->clear();
      (*sw)->set_instance(&event);
      (*sw)->push();
      }
    }
};
#endif

#endif // TreeAssist_h
