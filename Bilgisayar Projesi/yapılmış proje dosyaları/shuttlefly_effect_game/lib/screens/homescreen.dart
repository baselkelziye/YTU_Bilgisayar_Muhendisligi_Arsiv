import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import '../database/allmethods.dart';
import '../database/allvariables.dart';
import '../database/theme.dart';

class HomeScreen extends StatelessWidget {
  const HomeScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        width: double.infinity,
        height: double.infinity,
        decoration: const BoxDecoration(
          image: DecorationImage(
            image: AssetImage('assets/shuttlefly_effect_bg.png'),
            fit: BoxFit.cover,
          ),
        ),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            AnimatedContainer(
              duration: const Duration(milliseconds: 0),
              width: MediaQuery.of(context).size.width / 2,
              height: MediaQuery.of(context).size.height * 2 / 3,
              margin: const EdgeInsets.all(5),
              decoration: const BoxDecoration(
                image: DecorationImage(
                  fit: BoxFit.contain,
                  image: AssetImage('assets/shuttlefly_effect_logo.png'),
                ),
              ),
            ),
            Container(
              width: MediaQuery.of(context).size.width / 4,
              margin: const EdgeInsets.all(5),
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: const [
                  NewGameButton(),
                  ContinueButton(),
                  ExitButton(),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}

// EXIT BOX
class ExitBox extends StatelessWidget {
  const ExitBox({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      child: FittedBox(
        child: Container(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Container(
                alignment: Alignment.center,
                margin: const EdgeInsets.all(5),
                height: 50,
                child: Text(
                  'ARE YOU SURE?',
                  textAlign: TextAlign.center,
                  style: GoogleFonts.fredokaOne(
                    color: Colors.black,
                    fontSize: 20,
                  ),
                ),
              ),
              const NoButton(),
              const YesButton(),
            ],
          ),
          width: 200,
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

// RESTART BOX
class RestartBox extends StatelessWidget {
  const RestartBox({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      child: FittedBox(
        child: Container(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Container(
                alignment: Alignment.center,
                margin: const EdgeInsets.all(5),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      'ARE YOU SURE?',
                      textAlign: TextAlign.center,
                      style: GoogleFonts.fredokaOne(
                        color: Colors.black,
                        fontSize: 20,
                      ),
                    ),
                    Text(
                      'Your previous progress\nwill be deleted.',
                      textAlign: TextAlign.center,
                      style: GoogleFonts.fredokaOne(
                        color: Color(sePinkyRed),
                        fontSize: 15,
                      ),
                    ),
                  ],
                ),
              ),
              const NoButton2(),
              const YesButton2(),
            ],
          ),
          width: 200,
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

// NO SAVED DATA BOX
class NoDataBox extends StatelessWidget {
  const NoDataBox({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      child: FittedBox(
        child: Container(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Expanded(
                    child: Container(
                      child: Text(
                        'NO DATA!',
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
                alignment: Alignment.topCenter,
                margin: const EdgeInsets.all(5),
                child: SingleChildScrollView(
                  physics: const BouncingScrollPhysics(),
                  child: Text(
                    'There is no progress saved. You should start a new game.',
                    textAlign: TextAlign.center,
                    style: GoogleFonts.fredokaOne(
                      color: Colors.black,
                      fontSize: 13,
                    ),
                  ),
                ),
              ),
            ],
          ),
          width: 200,
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
class NewGameButton extends StatelessWidget {
  const NewGameButton({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () async {
        if (await DatabaseService().dataExists) {
          showDialog(
            context: context,
            builder: (BuildContext context) {
              return AlertDialog(
                content: const RestartBox(),
                contentPadding: EdgeInsets.zero,
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(10),
                ),
              );
            },
          );
        } else {
          Navigator.pushNamed(context, '/storyscreen');
        }
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'NEW GAME',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 20,
          ),
        ),
        height: seButtonHeight,
        decoration: BoxDecoration(
          color: Color(seLightBlue),
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          border: Border.all(
            width: seBorderWidth,
            color: Color(seBlue),
          ),
        ),
        margin: const EdgeInsets.all(5),
      ),
    );
  }
}

class ContinueButton extends StatelessWidget {
  const ContinueButton({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () async {
        if (await DatabaseService().dataExists) {
          char1 = await DatabaseService().getCharFromLocal(1);
          char2 = await DatabaseService().getCharFromLocal(2);
          char3 = await DatabaseService().getCharFromLocal(3);

          event.eventID = await DatabaseService().getEventIDFromLocal();
          event = await DatabaseService().getEvent(event.eventID!);

          Navigator.pushNamed(context, '/gamescreen');
        } else {
          showDialog(
            context: context,
            builder: (BuildContext context) {
              return AlertDialog(
                content: const NoDataBox(),
                contentPadding: EdgeInsets.zero,
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(10),
                ),
              );
            },
          );
        }
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'CONTINUE',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 20,
          ),
        ),
        height: seButtonHeight,
        decoration: BoxDecoration(
          color: Color(sePinkyRed),
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          border: Border.all(
            width: seBorderWidth,
            color: Color(seDarkPinkyRed),
          ),
        ),
        margin: const EdgeInsets.all(5),
      ),
    );
  }
}

class ExitButton extends StatelessWidget {
  const ExitButton({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {
        showDialog(
          context: context,
          builder: (BuildContext context) {
            return AlertDialog(
              content: const ExitBox(),
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
          'EXIT',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 20,
          ),
        ),
        height: seButtonHeight,
        decoration: BoxDecoration(
          color: Color(seGrey),
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          border: Border.all(
            width: seBorderWidth,
            color: Color(seDarkGrey),
          ),
        ),
        margin: const EdgeInsets.all(5),
      ),
    );
  }
}

class YesButton extends StatelessWidget {
  const YesButton({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {
        SystemNavigator.pop(); // EXIT
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'YES',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 20,
          ),
        ),
        height: seButtonHeight,
        decoration: BoxDecoration(
          color: Color(sePinkyRed),
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          border: Border.all(
            width: seBorderWidth,
            color: Color(seDarkPinkyRed),
          ),
        ),
        margin: const EdgeInsets.all(5),
      ),
    );
  }
}

class NoButton extends StatelessWidget {
  const NoButton({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {
        Navigator.pop(context);
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'NO',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 20,
          ),
        ),
        height: seButtonHeight,
        decoration: BoxDecoration(
          color: Color(seGrey),
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          border: Border.all(
            width: seBorderWidth,
            color: Color(seDarkGrey),
          ),
        ),
        margin: const EdgeInsets.all(5),
      ),
    );
  }
}

class YesButton2 extends StatelessWidget {
  const YesButton2({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () async {
        await DatabaseService().eraseSavedData();
        Navigator.popAndPushNamed(context, '/storyscreen');
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'YES',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 20,
          ),
        ),
        height: seButtonHeight,
        decoration: BoxDecoration(
          color: Color(sePinkyRed),
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          border: Border.all(
            width: seBorderWidth,
            color: Color(seDarkPinkyRed),
          ),
        ),
        margin: const EdgeInsets.all(5),
      ),
    );
  }
}

class NoButton2 extends StatelessWidget {
  const NoButton2({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {
        Navigator.pop(context);
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'NO',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 20,
          ),
        ),
        height: seButtonHeight,
        decoration: BoxDecoration(
          color: Color(seGrey),
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          border: Border.all(
            width: seBorderWidth,
            color: Color(seDarkGrey),
          ),
        ),
        margin: const EdgeInsets.all(5),
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
