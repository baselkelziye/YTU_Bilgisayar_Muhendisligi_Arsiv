import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

import '/screens/homescreen.dart';
import '/screens/choosescreen.dart';
import '/screens/gamescreen.dart';
import '/screens/storyscreen.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  SystemChrome.setEnabledSystemUIMode(SystemUiMode.immersive,
      overlays: [SystemUiOverlay.bottom]);
  SystemChrome.setPreferredOrientations([DeviceOrientation.landscapeLeft])
      .then((_) {
    runApp(const MyApp());
  });
}

// App Widget
class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      initialRoute: '/homescreen',
      routes: {
        '/homescreen': (context) => const HomeScreen(),
        '/storyscreen': (context) => const StoryScreen(),
        '/choosescreen': (context) => const ChooseScreen(),
        '/gamescreen': (context) => const GameScreen(),
      },
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        highlightColor: Colors.transparent,
        splashFactory: NoSplash.splashFactory,
      ),
    );
  }
}
