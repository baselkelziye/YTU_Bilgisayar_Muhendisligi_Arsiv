class Event {
  int? eventID; // event database ID
  String? title; // events title
  String? desc; // event description

  bool? chosenH;
  bool? chosenO;
  bool? chosenP;
  bool? chosenE;

  bool? otherH;
  bool? otherO;
  bool? otherP;
  bool? otherE;

  Event({
    this.eventID,
    this.title,
    this.desc,
    this.chosenH,
    this.chosenO,
    this.chosenP,
    this.chosenE,
    this.otherH,
    this.otherO,
    this.otherP,
    this.otherE,
  });
}

class Selection {
  int? selID; // selection database ID
  String? desc; // selection description
  bool? success; // selection description

  Selection({
    this.selID,
    this.desc,
    this.success,
  });
}

class Character {
  int? charID; // character ID
  String? charName; // character name
  String? imgURL; // character's image URL

  int? skillID; // skill ID
  String? skillName; // skill name
  String? skillDesc; // skill description

  // STATES
  int? health = 100;
  int? oxygen = 100;
  int? psycho = 100;
  int? energy = 100;

  Character({
    this.charID,
    this.charName,
    this.imgURL,
    this.skillID,
    this.skillName,
    this.skillDesc,
    this.health,
    this.oxygen,
    this.psycho,
    this.energy,
  });
}

class Story {
  String? title; // skill name
  String? desc; // skill description

  Story({
    this.title,
    this.desc,
  });
}
