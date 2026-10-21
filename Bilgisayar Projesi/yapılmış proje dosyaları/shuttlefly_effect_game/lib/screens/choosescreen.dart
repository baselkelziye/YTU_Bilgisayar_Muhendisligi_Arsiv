import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import '../database/allclasses.dart';
import '../database/allmethods.dart';
import '../database/allvariables.dart';
import '../database/theme.dart';

class ChooseScreen extends StatelessWidget {
  const ChooseScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color(seDarkBlue),
      body: Container(
        margin: const EdgeInsets.all(10),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const TopBarBox(),
            Expanded(
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Expanded(
                    flex: 1,
                    child: Column(
                      children: [
                        Expanded(
                          child: CharacterBox(
                            index: 1,
                          ),
                        ),
                        SkillBox(
                          index: 1,
                        ),
                      ],
                    ),
                  ),
                  Expanded(
                    flex: 1,
                    child: Column(
                      children: [
                        Expanded(
                          child: CharacterBox(
                            index: 2,
                          ),
                        ),
                        SkillBox(
                          index: 2,
                        ),
                      ],
                    ),
                  ),
                  Expanded(
                    flex: 1,
                    child: Column(
                      children: [
                        Expanded(
                          child: CharacterBox(
                            index: 3,
                          ),
                        ),
                        SkillBox(
                          index: 3,
                        ),
                      ],
                    ),
                  ),
                ],
              ),
            )
          ],
        ),
      ),
    );
  }
}

// CHARACTER NAME AND PICTURE BOX
class CharacterBox extends StatefulWidget {
  final int index;

  CharacterBox({
    Key? key,
    required this.index,
  }) : super(key: key);
  @override
  _CharacterBoxState createState() => _CharacterBoxState();
}

class _CharacterBoxState extends State<CharacterBox> {
  var counter = 0;
  @override
  Widget build(BuildContext context) {
    return FutureBuilder<Character>(
      future: DatabaseService().getOnlyChar((widget.index - 1) * 5 + counter),
      builder: (context, snapshot) {
        if (!snapshot.hasData) {
          return Container(
            alignment: Alignment.center,
            child: Text(
              'Loading...',
              textAlign: TextAlign.center,
              style: GoogleFonts.fredokaOne(
                color: Colors.white,
                fontSize: 30,
              ),
            ),
          );
        }
        var char = snapshot.data!;
        switch (widget.index) {
          case 1:
            char1.charID = char.charID;
            char1.charName = char.charName;
            char1.imgURL = char.imgURL;
            break;
          case 2:
            char2.charID = char.charID;
            char2.charName = char.charName;
            char2.imgURL = char.imgURL;
            break;
          case 3:
            char3.charID = char.charID;
            char3.charName = char.charName;
            char3.imgURL = char.imgURL;
            break;
        }
        return Container(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Container(
                alignment: Alignment.center,
                child: Text(
                  'CHARACTER ${widget.index}',
                  textAlign: TextAlign.center,
                  style: GoogleFonts.fredokaOne(
                    color: Color(seDarkPinkyRed),
                    fontSize: 20,
                  ),
                ),
                margin: const EdgeInsets.only(top: 10),
              ),
              Expanded(
                flex: 1,
                child: AspectRatio(
                  aspectRatio: 1.0,
                  child: Container(
                    margin: const EdgeInsets.all(5),
                    decoration: BoxDecoration(
                      image: DecorationImage(
                        fit: BoxFit.cover,
                        image: NetworkImage(
                          char.imgURL!,
                        ),
                      ),
                      shape: BoxShape.circle,
                      border: Border.all(
                        width: seBorderWidth,
                        color: Color(seDarkCream),
                      ),
                    ),
                  ),
                ),
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Expanded(
                    flex: 1,
                    child: InkWell(
                      onTap: () async {
                        if (counter == 0) {
                          counter = 4;
                        } else {
                          counter--;
                        }
                        setState(() {});
                      },
                      child: Container(
                        alignment: Alignment.center,
                        child: Text(
                          '<',
                          textAlign: TextAlign.center,
                          style: GoogleFonts.fredokaOne(
                            color: Colors.white,
                            fontSize: 35,
                          ),
                        ),
                        height: seTextBoxHeight,
                        decoration: BoxDecoration(
                          color: Color(sePinkyRed),
                          borderRadius:
                              const BorderRadius.all(Radius.circular(10)),
                          border: Border.all(
                            width: seBorderWidth,
                            color: Color(seDarkPinkyRed),
                          ),
                        ),
                        margin: const EdgeInsets.all(5),
                      ),
                    ),
                  ),
                  Expanded(
                    flex: 2,
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Container(
                          alignment: Alignment.center,
                          child: Text(
                            char.charName!,
                            textAlign: TextAlign.center,
                            style: GoogleFonts.fredokaOne(
                              color: Colors.black,
                              fontSize: 20,
                            ),
                          ),
                          height: seTextBoxHeight,
                          decoration: BoxDecoration(
                            color: Colors.white,
                            borderRadius:
                                const BorderRadius.all(Radius.circular(10)),
                            border: Border.all(
                              width: seBorderWidth,
                              color: Color(seDarkCream),
                            ),
                          ),
                          margin: const EdgeInsets.only(top: 5, bottom: 5),
                        ),
                      ],
                    ),
                  ),
                  Expanded(
                    flex: 1,
                    child: InkWell(
                      onTap: () {
                        if (counter == 4) {
                          counter = 0;
                        } else {
                          counter++;
                        }
                        setState(() {});
                      },
                      child: Container(
                        alignment: Alignment.center,
                        child: Text(
                          '>',
                          textAlign: TextAlign.center,
                          style: GoogleFonts.fredokaOne(
                            color: Colors.white,
                            fontSize: 35,
                          ),
                        ),
                        height: seTextBoxHeight,
                        decoration: BoxDecoration(
                          color: Color(sePinkyRed),
                          borderRadius:
                              const BorderRadius.all(Radius.circular(10)),
                          border: Border.all(
                            width: seBorderWidth,
                            color: Color(seDarkPinkyRed),
                          ),
                        ),
                        margin: const EdgeInsets.all(5),
                      ),
                    ),
                  ),
                ],
              ),
            ],
          ),
          margin: const EdgeInsets.all(5),
          decoration: BoxDecoration(
            color: Color(seLightCream),
            borderRadius: const BorderRadius.all(Radius.circular(10)),
            border: Border.all(
              width: seBorderWidth,
              color: Color(seCream),
            ),
          ),
        );
      },
    );
  }
}

// CHARACTER NAME AND PICTURE BOX
class SkillBox extends StatefulWidget {
  final int index;
  SkillBox({
    Key? key,
    required this.index,
  }) : super(key: key);
  @override
  _SkillBoxState createState() => _SkillBoxState();
}

class _SkillBoxState extends State<SkillBox> {
  var counter = 0;
  @override
  Widget build(BuildContext context) {
    return FutureBuilder<Character>(
      future: DatabaseService().getOnlySkill(counter),
      builder: (context, snapshot) {
        if (!snapshot.hasData) return Container();
        var char = snapshot.data!;
        switch (widget.index) {
          case 1:
            char1.skillID = char.skillID;
            char1.skillName = char.skillName;
            char1.skillDesc = char.skillDesc;
            break;
          case 2:
            char2.skillID = char.skillID;
            char2.skillName = char.skillName;
            char2.skillDesc = char.skillDesc;
            break;
          case 3:
            char3.skillID = char.skillID;
            char3.skillName = char.skillName;
            char3.skillDesc = char.skillDesc;
            break;
          default:
        }
        return Container(
          child: Column(
            children: [
              Container(
                alignment: Alignment.center,
                child: Text(
                  'SKILL OF ${widget.index}',
                  textAlign: TextAlign.center,
                  style: GoogleFonts.fredokaOne(
                    color: Color(seDarkBlue),
                    fontSize: 20,
                  ),
                ),
                margin: const EdgeInsets.only(top: 5),
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Expanded(
                    flex: 1,
                    child: InkWell(
                      onTap: () {
                        if (counter == 0) {
                          counter = 9;
                        } else {
                          counter--;
                        }
                        setState(() {});
                      },
                      child: Container(
                        alignment: Alignment.center,
                        child: Text(
                          '<',
                          textAlign: TextAlign.center,
                          style: GoogleFonts.fredokaOne(
                            color: Colors.white,
                            fontSize: 35,
                          ),
                        ),
                        height: seTextBoxHeight,
                        decoration: BoxDecoration(
                          color: Color(seLightBlue),
                          borderRadius:
                              const BorderRadius.all(Radius.circular(10)),
                          border: Border.all(
                            width: seBorderWidth,
                            color: Color(seBlue),
                          ),
                        ),
                        margin: const EdgeInsets.all(5),
                      ),
                    ),
                  ),
                  Expanded(
                    flex: 2,
                    child: InkWell(
                      onTap: () {
                        showDialog(
                          context: context,
                          builder: (BuildContext context) {
                            return AlertDialog(
                              content: SkillDescBox(
                                skillName: char.skillName!,
                                skillDesc: char.skillDesc!,
                              ),
                              contentPadding: EdgeInsets.zero,
                              shape: RoundedRectangleBorder(
                                borderRadius: BorderRadius.circular(10),
                              ),
                            );
                          },
                        );
                      },
                      child: Container(
                        alignment: Alignment.center,
                        child: Text(
                          char.skillName!,
                          textAlign: TextAlign.center,
                          style: GoogleFonts.fredokaOne(
                            color: Colors.black,
                            fontSize: 15,
                          ),
                        ),
                        height: seTextBoxHeight,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          borderRadius:
                              const BorderRadius.all(Radius.circular(10)),
                          border: Border.all(
                            width: seBorderWidth,
                            color: Color(seDarkGrey),
                          ),
                        ),
                        margin: const EdgeInsets.only(top: 5, bottom: 5),
                      ),
                    ),
                  ),
                  Expanded(
                    flex: 1,
                    child: InkWell(
                      onTap: () {
                        if (counter == 9) {
                          counter = 0;
                        } else {
                          counter++;
                        }

                        // GEREKLİ İŞLEMLER <======

                        setState(() {});
                      },
                      child: Container(
                        alignment: Alignment.center,
                        child: Text(
                          '>',
                          textAlign: TextAlign.center,
                          style: GoogleFonts.fredokaOne(
                            color: Colors.white,
                            fontSize: 35,
                          ),
                        ),
                        height: seTextBoxHeight,
                        decoration: BoxDecoration(
                          color: Color(seLightBlue),
                          borderRadius:
                              const BorderRadius.all(Radius.circular(10)),
                          border: Border.all(
                            width: seBorderWidth,
                            color: Color(seBlue),
                          ),
                        ),
                        margin: const EdgeInsets.all(5),
                      ),
                    ),
                  ),
                ],
              ),
            ],
          ),
          margin: const EdgeInsets.all(5),
          decoration: BoxDecoration(
            color: Color(seLightGrey),
            borderRadius: const BorderRadius.all(Radius.circular(10)),
            border: Border.all(
              width: seBorderWidth,
              color: Color(seGrey),
            ),
          ),
        );
      },
    );
  }
}

class TopBarBox extends StatelessWidget {
  const TopBarBox({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      child: Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          const BackButton(),
          Expanded(
            child: Text(
              'CHOOSE CHARACTERS',
              textAlign: TextAlign.center,
              style: GoogleFonts.fredokaOne(
                color: Colors.white,
                fontSize: 25,
              ),
            ),
          ),
          const DoneButton(),
        ],
      ),
      margin: const EdgeInsets.all(5),
      padding: const EdgeInsets.all(0),
      decoration: BoxDecoration(
        color: Color(seLightBlue),
        borderRadius: const BorderRadius.all(Radius.circular(10)),
        border: Border.all(
          width: seBorderWidth,
          color: Color(seBlue),
        ),
      ),
    );
  }
}

// SKILL DESCRIPTION BOX
class SkillDescBox extends StatelessWidget {
  final String skillName;
  final String skillDesc;
  const SkillDescBox(
      {Key? key, required this.skillName, required this.skillDesc})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      child: FittedBox(
        child: Container(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Row(
                children: [
                  Expanded(
                    child: Container(
                      child: Text(
                        skillName,
                        textAlign: TextAlign.left,
                        style: GoogleFonts.fredokaOne(
                          color: Colors.black,
                          fontSize: 25,
                        ),
                      ),
                      margin: const EdgeInsets.only(left: 10),
                    ),
                  ),
                  const MenuCloseButton(),
                ],
              ),
              Container(
                alignment: Alignment.center,
                margin: const EdgeInsets.all(5),
                child: SingleChildScrollView(
                  physics: const BouncingScrollPhysics(),
                  child: Text(
                    skillDesc,
                    textAlign: TextAlign.left,
                    style: GoogleFonts.fredokaOne(
                      color: Colors.black,
                      fontSize: 15,
                    ),
                  ),
                ),
              ),
            ],
          ),
          width: 300,
          margin: const EdgeInsets.all(15),
        ),
      ),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: const BorderRadius.all(Radius.circular(10)),
        border: Border.all(
          width: seBorderWidth,
          color: Color(seGrey),
        ),
      ),
    );
  }
}

// BUTTONS
class BackButton extends StatelessWidget {
  const BackButton({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {
        Navigator.pop(context);
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'BACK',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 18,
          ),
        ),
        height: 50,
        width: 100,
      ),
    );
  }
}

class DoneButton extends StatelessWidget {
  const DoneButton({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () async {
        char1.health = defaultStateValue;
        char1.oxygen = defaultStateValue;
        char1.psycho = defaultStateValue;
        char1.energy = defaultStateValue;

        char2.health = defaultStateValue;
        char2.oxygen = defaultStateValue;
        char2.psycho = defaultStateValue;
        char2.energy = defaultStateValue;

        char3.health = defaultStateValue;
        char3.oxygen = defaultStateValue;
        char3.psycho = defaultStateValue;
        char3.energy = defaultStateValue;

        eventPageIndex = 0;
        await DatabaseService().saveCharacters();
        event = await DatabaseService().getRandomEvent();
        await DatabaseService().saveEventID();
        Navigator.popAndPushNamed(context, '/gamescreen');
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'DONE',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 18,
          ),
        ),
        height: 50,
        width: 100,
      ),
    );
  }
}

class MenuCloseButton extends StatelessWidget {
  const MenuCloseButton({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {
        Navigator.pop(context);
        // SAVE GAME AND GO BACK TO MAIN MENU
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'X',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Color(seDarkPinkyRed),
            fontSize: 30,
          ),
        ),
        height: 50,
        width: 50,
        decoration: BoxDecoration(
          color: Color(seLightGrey),
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          border: Border.all(
            width: seBorderWidth,
            color: Color(seGrey),
          ),
        ),
        margin: const EdgeInsets.all(5),
      ),
    );
  }
}
