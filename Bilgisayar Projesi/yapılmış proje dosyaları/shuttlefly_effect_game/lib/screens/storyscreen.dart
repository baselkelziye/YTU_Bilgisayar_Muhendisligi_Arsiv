import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import '../database/allvariables.dart';
import '../database/theme.dart';

class StoryScreen extends StatelessWidget {
  const StoryScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color(seDarkBlue),
      body: Container(
        width: double.infinity,
        height: double.infinity,
        decoration: const BoxDecoration(
          image: DecorationImage(
            image: AssetImage('assets/shuttlefly_effect_bg.png'),
            fit: BoxFit.cover,
          ),
        ),
        child: Container(
          margin: const EdgeInsets.fromLTRB(50, 20, 50, 0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Container(
                child: Text(
                  story.title!,
                  textAlign: TextAlign.center,
                  style: GoogleFonts.fredokaOne(
                    color: Color(seLightBlue),
                    fontSize: 25,
                  ),
                ),
                margin: const EdgeInsets.only(top: 30, bottom: 30),
              ),
              Expanded(
                child: SingleChildScrollView(
                  physics: const BouncingScrollPhysics(),
                  child: Container(
                    child: Text(
                      story.desc!,
                      textAlign: TextAlign.center,
                      overflow: TextOverflow.fade,
                      style: GoogleFonts.fredokaOne(
                        color: Colors.white,
                        fontSize: 20,
                      ),
                    ),
                    margin: const EdgeInsets.fromLTRB(10, 0, 10, 10),
                  ),
                ),
              ),
              Container(
                alignment: Alignment.centerRight,
                child: const NextButton(),
              ),
            ],
          ),
        ),
      ),
    );
  }
}

class NextButton extends StatelessWidget {
  const NextButton({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {
        Navigator.popAndPushNamed(context, '/choosescreen');
      },
      child: Container(
        alignment: Alignment.center,
        child: Text(
          'NEXT',
          textAlign: TextAlign.center,
          style: GoogleFonts.fredokaOne(
            color: Colors.white,
            fontSize: 30,
          ),
        ),
        height: 50,
        width: 150,
        decoration: BoxDecoration(
          color: Color(sePinkyRed),
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          border: Border.all(
            width: seBorderWidth,
            color: Color(seDarkPinkyRed),
          ),
        ),
        margin: const EdgeInsets.all(20),
      ),
    );
  }
}
