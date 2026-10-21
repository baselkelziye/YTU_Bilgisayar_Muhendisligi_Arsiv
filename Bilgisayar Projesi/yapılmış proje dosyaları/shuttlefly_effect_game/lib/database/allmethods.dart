import 'dart:math';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'allclasses.dart';
import 'allvariables.dart';

class DatabaseService {
  FirebaseFirestore db = FirebaseFirestore.instance;

  // GET FROM FIREBASE
  Future<Character> getOnlyChar(int id) async {
    var char = await db.collection('characters').doc(id.toString()).get();

    return Character(
      charID: int.parse(char.id),
      charName: char.get('name'),
      imgURL: char.get('imgURL'),
    );
  }

  Future<Character> getOnlySkill(int id) async {
    var skills = await db.collection('skills').doc(id.toString()).get();

    return Character(
      skillID: int.parse(skills.id),
      skillName: skills.get('title'),
      skillDesc: skills.get('desc'),
    );
  }

  Future<Character> getFullChar(int id, int skillId) async {
    var char = await db.collection('characters').doc(id.toString()).get();
    var skills = await db.collection('skills').doc(skillId.toString()).get();

    return Character(
      charID: int.parse(char.id),
      charName: char.get('name'),
      imgURL: char.get('imgURL'),
      skillID: int.parse(skills.id),
      skillName: skills.get('title'),
      skillDesc: skills.get('desc'),
    );
  }

  Future<Event> getEvent(int id) async {
    var evt = await db.collection('events').doc(id.toString()).get();

    return Event(
      eventID: int.parse(evt.id),
      title: evt.get('title'),
      desc: evt.get('desc'),
      chosenH: evt.get('chosenH'),
      chosenO: evt.get('chosenO'),
      chosenP: evt.get('chosenP'),
      chosenE: evt.get('chosenE'),
      otherH: evt.get('otherH'),
      otherO: evt.get('otherO'),
      otherP: evt.get('otherP'),
      otherE: evt.get('otherE'),
    );
  }

  Future<Event> getRandomEvent() async {
    var event = await db.collection('events').doc('eventCount').get();
    int eventCount = event.get('count');

    Random random = Random();
    int randomNumber = random.nextInt(eventCount);

    return DatabaseService().getEvent(randomNumber);
  }

  Future<Selection> getSelection(int id) async {
    var select = await db
        .collection('events')
        .doc(event.eventID.toString())
        .collection('selections')
        .doc(id.toString())
        .get();

    return Selection(
      selID: int.parse(select.id),
      success: select.get('success'),
      desc: select.get('desc'),
    );
  }

  // SAVE TO LOCAL
  Future saveCharacters() async {
    final _prefs = await SharedPreferences.getInstance();
    _prefs.setBool('dataExists', true);

    _prefs.setInt('char1_charID', char1.charID!);
    _prefs.setInt('char1_skillID', char1.skillID!);
    _prefs.setInt('char1_H', char1.health!);
    _prefs.setInt('char1_O', char1.oxygen!);
    _prefs.setInt('char1_P', char1.psycho!);
    _prefs.setInt('char1_E', char1.energy!);

    _prefs.setInt('char2_charID', char2.charID!);
    _prefs.setInt('char2_skillID', char2.skillID!);
    _prefs.setInt('char2_H', char2.health!);
    _prefs.setInt('char2_O', char2.oxygen!);
    _prefs.setInt('char2_P', char2.psycho!);
    _prefs.setInt('char2_E', char2.energy!);

    _prefs.setInt('char3_charID', char3.charID!);
    _prefs.setInt('char3_skillID', char3.skillID!);
    _prefs.setInt('char3_H', char3.health!);
    _prefs.setInt('char3_O', char3.oxygen!);
    _prefs.setInt('char3_P', char3.psycho!);
    _prefs.setInt('char3_E', char3.energy!);
  }

  Future saveStates() async {
    final _prefs = await SharedPreferences.getInstance();

    _prefs.setInt('char1_H', char1.health!);
    _prefs.setInt('char1_O', char1.oxygen!);
    _prefs.setInt('char1_P', char1.psycho!);
    _prefs.setInt('char1_E', char1.energy!);

    _prefs.setInt('char2_H', char2.health!);
    _prefs.setInt('char2_O', char2.oxygen!);
    _prefs.setInt('char2_P', char2.psycho!);
    _prefs.setInt('char2_E', char2.energy!);

    _prefs.setInt('char3_H', char3.health!);
    _prefs.setInt('char3_O', char3.oxygen!);
    _prefs.setInt('char3_P', char3.psycho!);
    _prefs.setInt('char3_E', char3.energy!);
  }

  Future saveEventID() async {
    final _prefs = await SharedPreferences.getInstance();

    _prefs.setInt('eventID', event.eventID!);
  }

  Future<bool> get dataExists async {
    final _prefs = await SharedPreferences.getInstance();
    return _prefs.getBool('dataExists') ?? false;
  }

  Future<Character> getCharFromLocal(int ID) async {
    final _prefs = await SharedPreferences.getInstance();

    var charID = _prefs.getInt('char${ID}_charID');
    var skillID = _prefs.getInt('char${ID}_skillID');
    var char = await getFullChar(charID!, skillID!);

    char.health = _prefs.getInt('char${ID}_H');
    char.oxygen = _prefs.getInt('char${ID}_O');
    char.psycho = _prefs.getInt('char${ID}_P');
    char.energy = _prefs.getInt('char${ID}_E');

    return char;
  }

  Future<int> getEventIDFromLocal() async {
    final _prefs = await SharedPreferences.getInstance();

    return _prefs.getInt('eventID')!;
  }

  Future eraseSavedData() async {
    final _prefs = await SharedPreferences.getInstance();
    _prefs.clear();
  }
}

void manageStates(Character char1, Character char2, Character char3) {
  if (event.chosenH!) {
    if (selection.success!) {
      char1.health = char1.health! + currentCharState;
      if (char1.health! > maxtStateValue) {
        char1.health = maxtStateValue;
      }
    } else {
      char1.health = char1.health! - currentCharState;
      if (char1.health! < 0) {
        char1.health = 0;
      }
    }
  }

  if (event.chosenO!) {
    if (selection.success!) {
      char1.oxygen = char1.oxygen! + currentCharState;
      if (char1.oxygen! > maxtStateValue) {
        char1.oxygen = maxtStateValue;
      }
    } else {
      char1.oxygen = char1.oxygen! - currentCharState;
      if (char1.oxygen! < 0) {
        char1.oxygen = 0;
      }
    }
  }

  if (event.chosenP!) {
    if (selection.success!) {
      char1.psycho = char1.psycho! + currentCharState;
      if (char1.psycho! > maxtStateValue) {
        char1.psycho = maxtStateValue;
      }
    } else {
      char1.psycho = char1.psycho! - currentCharState;
      if (char1.psycho! < 0) {
        char1.psycho = 0;
      }
    }
  }

  if (event.chosenE!) {
    if (selection.success!) {
      char1.energy = char1.energy! + currentCharState;
      if (char1.energy! > maxtStateValue) {
        char1.energy = maxtStateValue;
      }
    } else {
      char1.energy = char1.energy! - currentCharState;
      if (char1.energy! < 0) {
        char1.energy = 0;
      }
    }
  }

  if (event.otherH!) {
    if (selection.success!) {
      char2.health = char2.health! + otherCharState;
      char3.health = char3.health! + otherCharState;
      if (char2.health! > maxtStateValue) {
        char2.health = maxtStateValue;
      }
      if (char3.health! > maxtStateValue) {
        char3.health = maxtStateValue;
      }
    } else {
      char2.health = char2.health! - otherCharState;
      char3.health = char3.health! - otherCharState;
      if (char2.health! < 0) {
        char2.health = 0;
      }
      if (char3.health! < 0) {
        char3.health = 0;
      }
    }
  }

  if (event.otherO!) {
    if (selection.success!) {
      char2.oxygen = char2.oxygen! + otherCharState;
      char3.oxygen = char3.oxygen! + otherCharState;
      if (char2.oxygen! > maxtStateValue) {
        char2.oxygen = maxtStateValue;
      }
      if (char3.oxygen! > maxtStateValue) {
        char3.oxygen = maxtStateValue;
      }
    } else {
      char2.oxygen = char2.oxygen! - otherCharState;
      char3.oxygen = char3.oxygen! - otherCharState;
      if (char2.oxygen! < 0) {
        char2.oxygen = 0;
      }
      if (char3.oxygen! < 0) {
        char3.oxygen = 0;
      }
    }
  }

  if (event.otherP!) {
    if (selection.success!) {
      char2.psycho = char2.psycho! + otherCharState;
      char3.psycho = char3.psycho! + otherCharState;
      if (char2.psycho! > maxtStateValue) {
        char2.psycho = maxtStateValue;
      }
      if (char3.psycho! > maxtStateValue) {
        char3.psycho = maxtStateValue;
      }
    } else {
      char2.psycho = char2.psycho! - otherCharState;
      char3.psycho = char3.psycho! - otherCharState;
      if (char2.psycho! < 0) {
        char2.psycho = 0;
      }
      if (char3.psycho! < 0) {
        char3.psycho = 0;
      }
    }
  }

  if (event.otherE!) {
    if (selection.success!) {
      char2.energy = char2.energy! + otherCharState;
      char3.energy = char3.energy! + otherCharState;
      if (char2.energy! > maxtStateValue) {
        char2.energy = maxtStateValue;
      }
      if (char3.energy! > maxtStateValue) {
        char3.energy = maxtStateValue;
      }
    } else {
      char2.energy = char2.energy! - otherCharState;
      char3.energy = char3.energy! - otherCharState;
      if (char2.energy! < 0) {
        char2.energy = 0;
      }
      if (char3.energy! < 0) {
        char3.energy = 0;
      }
    }
  }
}

void skipManageStates() {
  if (event.otherH!) {
    if (selection.success!) {
      char1.health = char1.health! + 5;
      char2.health = char2.health! + 5;
      char3.health = char3.health! + 5;
      if (char1.health! > 100) {
        char1.health = 100;
      }
      if (char2.health! > 100) {
        char2.health = 100;
      }
      if (char3.health! > 100) {
        char3.health = 100;
      }
    } else {
      char1.health = char1.health! - 5;
      char2.health = char2.health! - 5;
      char3.health = char3.health! - 5;
      if (char1.health! < 0) {
        char1.health = 0;
      }
      if (char2.health! < 0) {
        char2.health = 0;
      }
      if (char3.health! < 0) {
        char3.health = 0;
      }
    }
  }

  if (event.otherO!) {
    if (selection.success!) {
      char1.oxygen = char1.oxygen! + 5;
      char2.oxygen = char2.oxygen! + 5;
      char3.oxygen = char3.oxygen! + 5;
      if (char1.oxygen! > 100) {
        char1.oxygen = 100;
      }
      if (char2.oxygen! > 100) {
        char2.oxygen = 100;
      }
      if (char3.oxygen! > 100) {
        char3.oxygen = 100;
      }
    } else {
      char1.oxygen = char1.oxygen! - 5;
      char2.oxygen = char2.oxygen! - 5;
      char3.oxygen = char3.oxygen! - 5;
      if (char1.oxygen! < 0) {
        char1.oxygen = 0;
      }
      if (char2.oxygen! < 0) {
        char2.oxygen = 0;
      }
      if (char3.oxygen! < 0) {
        char3.oxygen = 0;
      }
    }
  }

  if (event.otherP!) {
    if (selection.success!) {
      char1.psycho = char1.psycho! + 5;
      char2.psycho = char2.psycho! + 5;
      char3.psycho = char3.psycho! + 5;
      if (char1.psycho! > 100) {
        char1.psycho = 100;
      }
      if (char2.psycho! > 100) {
        char2.psycho = 100;
      }
      if (char3.psycho! > 100) {
        char3.psycho = 100;
      }
    } else {
      char1.psycho = char1.psycho! - 5;
      char2.psycho = char2.psycho! - 5;
      char3.psycho = char3.psycho! - 5;
      if (char1.psycho! < 0) {
        char1.psycho = 0;
      }
      if (char2.psycho! < 0) {
        char2.psycho = 0;
      }
      if (char3.psycho! < 0) {
        char3.psycho = 0;
      }
    }
  }

  if (event.otherE!) {
    if (selection.success!) {
      char1.energy = char1.energy! + 5;
      char2.energy = char2.energy! + 5;
      char3.energy = char3.energy! + 5;
      if (char1.energy! > 100) {
        char1.energy = 100;
      }
      if (char2.energy! > 100) {
        char2.energy = 100;
      }
      if (char3.energy! > 100) {
        char3.energy = 100;
      }
    } else {
      char1.energy = char1.energy! - 5;
      char2.energy = char2.energy! - 5;
      char3.energy = char3.energy! - 5;
      if (char1.energy! < 0) {
        char1.energy = 0;
      }
      if (char2.energy! < 0) {
        char2.energy = 0;
      }
      if (char3.energy! < 0) {
        char3.energy = 0;
      }
    }
  }
}

String checkStates() {
  String message = '';
  int char1Died = 0;
  int char2Died = 0;
  int char3Died = 0;
  if (char1.health! <= 0 ||
      char1.oxygen! <= 0 ||
      char1.psycho! <= 0 ||
      char1.energy! <= 0) {
    char1Died = 1;
  }
  if (char2.health! <= 0 ||
      char2.oxygen! <= 0 ||
      char2.psycho! <= 0 ||
      char2.energy! <= 0) {
    char2Died = 1;
  }
  if (char3.health! <= 0 ||
      char3.oxygen! <= 0 ||
      char3.psycho! <= 0 ||
      char3.energy! <= 0) {
    char3Died = 1;
  }

  if (char1Died == 1) {
    message = message + char1.charName!;
  }

  if (char2Died == 1) {
    if (char1Died == 1) {
      message = message + ', ';
    }
    message = message + char2.charName!;
  }

  if (char3Died == 1) {
    if (char1Died == 1 || char2Died == 1) {
      message = message + ', ';
    }
    message = message + char3.charName!;
  }

  if (message == '') {
    return '';
  } else {
    return message + ' eliminated.';
  }
}
