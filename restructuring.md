Author: David Hohn
Date: 13 Dec 2017

# Restructuring the LooseEventSaver

The goal is to split up the code that is now in the [LooseEventSaver](Root/ttHMultileptonLooseEventSaver.cxx) into smaller pieces. This will should make the code more maintainable, less buggy and easier to understand. More motivation for this in my AnalysisTop(AT)+ttHML tutorial on [24 Nov](https://indico.cern.ch/event/683759/).

In the end we want to be able to configure everything from the config file with nothing hardcoded in the Saver any more. To do this we have to write "Selectors" that can be loaded dynamically by AT. The base class is [EventSelectorBase](https://gitlab.cern.ch/atlas/athena/blob/21.2/PhysicsAnalysis/TopPhys/xAOD/TopEventSelectionTools/TopEventSelectionTools/EventSelectorBase.h). To be able to capsulate the code like that we need a way to centrally store information outside of these classes, e.g. one Selector defines what a muons is and then another Selector cuts on that definition, so that information needs to be available to both classes. This functionality is built into athena (StoreGate) and xAOD code (TStore). AT uses the TStore internally to store events, collections of objects (electrons, muons, taus, etc). All of these can be "retrieved" at any time, e.g. [here](https://gitlab.cern.ch/atlasHTop/ttHMultiAna/blob/master/Root/ttHMultileptonLooseEventSaver.cxx#L1911) I retrieved all calibrated jets without any cuts. However, since the top::Event will always be available in any class of AT, we can use it to organise this storing of information. We will make use of the xAOD decoration functionality to decorate the xAOD::EventInfo that is a member of the top::Event with a custom object for ttHML purposes.

In the end I imagine a config file that have a cutflow like so (my comments in parentheses), just suggesting names for the Selectors...:
```
SELECTION tthml
INITIAL
GRL
GOODCALO
PRIVTX
COUNTHISTO
JETCLEAN LooseBad
CREATETTHMLVARIABLES
SELECTMUONS tight (maybe some kind of configurability here)
SELECTELECTRONS verytight
SELECTTAUS antimedium
SELECTJETS jvt
SELECTBTAGS 70%
OVERLAPREMOVAL slidingDRformuons
NLEPTONS 15000 >= 2 (at least two elec+muon with pt>15GeV)
SSLEPTONS
NTAUS >= 1
TRIGGERSF
MUONSF
ELECTRONSF
BTAGSF
TAUSF
CALCULATESOMEMVA
DUPLICATEVETO
SAVE
```

## 0. Create Validation script

Can be very simple, like counting every type of object. This can be used everytime you make a change to the code, so you can be sure you keep the physics functionality the same and really just change the techincal aspects of the code.

Then always run it on the same test file after every of the below tasks are completed.

Time Estimate: couple of minutes

## 1. Decorate top::Event with custom ttHML object

As tthML object to hold our information we can use [ttHMultilepton::Variables](https://gitlab.cern.ch/atlasHTop/ttHMultiAna/blob/master/ttHMultilepton/Variables.h).

Right now we have one Variables object that is constructed in [LooseEventSaver::initialize](https://gitlab.cern.ch/atlasHTop/ttHMultiAna/blob/master/Root/ttHMultileptonLooseEventSaver.cxx#L195) and [cleared](https://gitlab.cern.ch/atlasHTop/ttHMultiAna/blob/master/Root/ttHMultileptonLooseEventSaver.cxx#L1798) for each event.

We will want to create one Variables for each top::Event, decorate it onto the EventInfo of the top::Event and replace the clearing with ordinary object destruction.

Technically this will a "Selector" e.g. "CREATEVARIABLES" that will simply be added to the cutflow in the AT config file.

Example of this in TTHbbLeptonic: [TTHbbCreateEvent](https://gitlab.cern.ch/atlasHTop/TTHbbAnalysis/blob/master/TTHbbLeptonic/Root/TTHbbCreateEvent.cxx)

Time Estimate: can be done very quickly by following the example.

## 2. Add vectors of elec, muon, tau, etc to Variables

We can use the xAOD types of all these objects. The objects already exists and are calibrated by AT. We just need to select a subset of these. An efficient concept to do this are VIEW containers. They are containers of pointers to xAOD objects that are already inside another container. Also see the (documentation in the AB tutorial)[https://atlassoftwaredocs.web.cern.ch/ABtutorial/basic_xaod_modify/#constdatavector-advancedoptional]

Example of how its done in AT: [defined as object, not pointer](https://gitlab.cern.ch/atlas/athena/blob/21.2/PhysicsAnalysis/TopPhys/xAOD/TopEvent/TopEvent/Event.h#L88), [constructed with VIEW_ELEMENTS argument](https://gitlab.cern.ch/atlas/athena/blob/21.2/PhysicsAnalysis/TopPhys/xAOD/TopEvent/TopEvent/Event.h#L52), then behaves like any other collection, sortable.

Essentially these vectors will replace goodEL, goodMu, goodJet, goodTau that are now created in the Saver.

Time Estimate: quick by following example.

## 3.a Create "Selectors" to select elec, muon, tau, etc

Move the object selection out of Saver. Basically everything in ttHMultileptonLooseEventSaver_Selection.cxx to seperate Selector classes.

Time Estimate: Need to get familiar with the BaseSelector class. Then each selector is straightforward.

## 3.b Create "Selector" for Overlap Removal

Probably best to use the ASG tool instead of our own implementation. ASG OLR should be configurable to do anything we want.
ASG tool is easy to use with xAOD containers, but I think it returns vectors of integers (0 or 1) ofthe OR decision (or maybe shallow copies?). Those would have to be translated into properly filled view containers.

Time Estimate: Need to get familiar with the ASG OR tool. Check the implementation in AT and the ASG documentation. Couple of days.

## 4. Create "Selector" for object decoration

Everything that is inside ttHMultileptonLooseEventSaver_Decorate.cxx to seperate Selector classes.

Time Estimate: quick

## 5. Create "Selector" for calculating per-event scale factors from per-object scale factors

This is currently done in the Saver.cxx as well as Saver_Selection.cxx. For the standard SFs (like b-tagging) we should see if we can reuse the AT code that already exists inside TopCorrections.

For trigger SFs we need to use a custom tool so that will definitely need a new Selector from us. (Maybe something for Tamara)

When we have this, we wont need the awkward construction with "Loose" lepton selections that are actually tight in the config files. We can then just use one most loose definition in the hardcoded AT object selection and then add different collections for tighter definitions with the selectors.

Time Estimate: This is probably the most complicated. several days?

## 6. Turn TruthMatchAlgo and TruthSelector into Selector

These are already a seperate classes, just need the Selector interface.

Time Estimate: quick

## 7. Other stuff

Everyhing in the Saver that is _not_ makeOutputVariable() or Wrap2() needs to be reviewed if it really has a place there.

Time Estimate: TBD

## General remarks

If you need to use a CP tool check if it already exists in the [TopToolStore](https://gitlab.cern.ch/atlas/athena/tree/21.2/PhysicsAnalysis/TopPhys/xAOD/TopCPTools/Root). If you need to create a new one store it in the asg::ToolStore (you might have to inherit from asg::AsgTool to be able to use it, I dont know if that is practicable for Selectors, so try it out)

## Workflow

I suggest to use the merge request workflow of git. This means every development happens in a seperate branch. This allows people to work in parallel. When the development in the branch is finished you create a merge request (MR) from the branch to master. The MR allows comments from other developers. Every MR should be approved (and therefore reviewed) by someone who is not the submitter. Direct commits to master should be avoided so that there are always at least two people looking at changes.

We can discuss all changes in mattermost.
