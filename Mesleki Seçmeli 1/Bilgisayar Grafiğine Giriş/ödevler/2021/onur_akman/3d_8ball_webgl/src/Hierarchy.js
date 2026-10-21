
class Hierarchy {
    constructor(gl) {

        const gameObjects = {};
        this.gameObjects = gameObjects;

        gameObjects["floor"] = new Cube(
            "floor",
            gl,
            vec4(0.6, 0.5, 0.5, 1.0),
            new Transform({ translation: translate(1, -28, 0), scaling: scalem(7000, -5000, 7000) })
        );

        //// The simulation ground
        gameObjects["table"] = new PoolTable(
            "table",
            gl,
            vec4(0.0, 1.0, 0.0, 1.0),
            new Transform({ scaling: scalem(100, -8, 56) })
        );

        gameObjects["leg1"] = new Leg(
            "leg1",
            gl,
            vec4(0.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(47, -8, 25), scaling: scalem(6, -20, 6) })
        );

        gameObjects["leg2"] = new Leg(
            "leg2",
            gl,
            vec4(0.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(-47, -8, 25), scaling: scalem(6, -20, 6) })
        );

        gameObjects["leg3"] = new Leg(
            "leg3",
            gl,
            vec4(0.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(-47, -8, -25), scaling: scalem(6, -20, 6) })
        );

        gameObjects["leg4"] = new Leg(
            "leg4",
            gl,
            vec4(0.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(47, -8, -25), scaling: scalem(6, -20, 6) })
        );

        gameObjects["face"] = new TableFace(
            "face",
            gl,
            vec4(0.0, 1.0, 0.0, 1.0),
            new Transform({ scaling: scalem(94, 0.1, 50) })
        );

        gameObjects["redCube1"] = new Ball(
            "redCube1",
            gl,
            vec4(1.0, 0.0, 0.0, 1.0),
            new Transform({ translation: translate(24, 0.2, -2) })
        );

        const script1 = new CubeScript();
        script1.gameObject = gameObjects["redCube1"];
        script1.gameObjects = this.gameObjects;
        gameObjects["redCube1"].component.script = script1;

        gameObjects["redCube2"] = new Ball(
            "redCube2",
            gl,
            vec4(1.0, 0.0, 0.0, 1.0),
            new Transform({ translation: translate(28, 0.2, 4) })
        );

        const script2 = new CubeScript();
        script2.gameObject = gameObjects["redCube2"];
        script2.gameObjects = this.gameObjects;
        gameObjects["redCube2"].component.script = script2;

        gameObjects["redCube3"] = new Ball(
            "redCube3",
            gl,
            vec4(1.0, 0.0, 0.0, 1.0),
            new Transform({ translation: translate(32, 0.2, 2) })
        );

        const script3 = new CubeScript();
        script3.gameObject = gameObjects["redCube3"];
        script3.gameObjects = this.gameObjects;
        gameObjects["redCube3"].component.script = script3;

        gameObjects["redCube4"] = new Ball(
            "redCube4",
            gl,
            vec4(1.0, 0.0, 0.0, 1.0),
            new Transform({ translation: translate(32, 0.2, -6) })
        );

        const script4 = new CubeScript();
        script4.gameObject = gameObjects["redCube4"];
        script4.gameObjects = this.gameObjects;
        gameObjects["redCube4"].component.script = script4;

        gameObjects["redCube5"] = new Ball(
            "redCube5",
            gl,
            vec4(1.0, 0.0, 0.0, 1.0),
            new Transform({ translation: translate(36, 0.2, -4) })
        );

        const script5 = new CubeScript();
        script5.gameObject = gameObjects["redCube5"];
        script5.gameObjects = this.gameObjects;
        gameObjects["redCube5"].component.script = script5;

        gameObjects["redCube6"] = new Ball(
            "redCube6",
            gl,
            vec4(1.0, 0.0, 0.0, 1.0),
            new Transform({ translation: translate(36, 0.2, 4) })
        );

        const script6 = new CubeScript();
        script6.gameObject = gameObjects["redCube6"];
        script6.gameObjects = this.gameObjects;
        gameObjects["redCube6"].component.script = script6;

        gameObjects["redCube7"] = new Ball(
            "redCube7",
            gl,
            vec4(1.0, 0.0, 0.0, 1.0),
            new Transform({ translation: translate(36, 0.2, 8) })
        );

        const script7 = new CubeScript();
        script7.gameObject = gameObjects["redCube7"];
        script7.gameObjects = this.gameObjects;
        gameObjects["redCube7"].component.script = script7;

        gameObjects["yellowCube1"] = new Ball(
            "yellowCube1",
            gl,
            vec4(1.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(20, 0.2, 0) })
        );

        const script8 = new CubeScript();
        script8.gameObject = gameObjects["yellowCube1"];
        script8.gameObjects = this.gameObjects;
        gameObjects["yellowCube1"].component.script = script8;

        gameObjects["yellowCube2"] = new Ball(
            "yellowCube2",
            gl,
            vec4(1.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(24, 0.2, 2) })
        );

        const script9 = new CubeScript();
        script9.gameObject = gameObjects["yellowCube2"];
        script9.gameObjects = this.gameObjects;
        gameObjects["yellowCube2"].component.script = script9;

        gameObjects["yellowCube3"] = new Ball(
            "yellowCube3",
            gl,
            vec4(1.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(28, 0.2, -4) })
        );

        const script10 = new CubeScript();
        script10.gameObject = gameObjects["yellowCube3"];
        script10.gameObjects = this.gameObjects;
        gameObjects["yellowCube3"].component.script = script10;

        gameObjects["yellowCube4"] = new Ball(
            "yellowCube4",
            gl,
            vec4(1.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(32, 0.2, -2) })
        );

        const script11 = new CubeScript();
        script11.gameObject = gameObjects["yellowCube4"];
        script11.gameObjects = this.gameObjects;
        gameObjects["yellowCube4"].component.script = script11;

        gameObjects["yellowCube5"] = new Ball(
            "yellowCube5",
            gl,
            vec4(1.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(32, 0.2, 6) })
        );

        const script12 = new CubeScript();
        script12.gameObject = gameObjects["yellowCube5"];
        script12.gameObjects = this.gameObjects;
        gameObjects["yellowCube5"].component.script = script12;

        gameObjects["yellowCube6"] = new Ball(
            "yellowCube6",
            gl,
            vec4(1.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(36, 0.2, 0) })
        );

        const script13 = new CubeScript();
        script13.gameObject = gameObjects["yellowCube6"];
        script13.gameObjects = this.gameObjects;
        gameObjects["yellowCube6"].component.script = script13;

        gameObjects["yellowCube7"] = new Ball(
            "yellowCube7",
            gl,
            vec4(1.0, 1.0, 0.0, 1.0),
            new Transform({ translation: translate(36, 0.2, -8) })
        );

        const script14 = new CubeScript();
        script14.gameObject = gameObjects["yellowCube7"];
        script14.gameObjects = this.gameObjects;
        gameObjects["yellowCube7"].component.script = script14;



        gameObjects["blackCube"] = new Ball(
            "blackCube",
            gl,
            vec4(0, 0, 0.0, 1.0),
            new Transform({ translation: translate(28, 0.2, 0) })
        );

        const script15 = new CubeScript();
        script15.gameObject = gameObjects["blackCube"];
        script15.gameObjects = this.gameObjects;
        gameObjects["blackCube"].component.script = script15;
        script15.isBlack = true;

        gameObjects["whiteCube"] = new Ball(
            "whiteCube",
            gl,
            vec4(1.0, 1, 1, 1.0),
            new Transform({ translation: translate(-24, 0.2, 0) })
        );

        const script0 = new WhiteCubeScript();
        script0.gameObject = gameObjects["whiteCube"];
        script0.gameObjects = this.gameObjects;
        gameObjects["whiteCube"].component.script = script0;



        gameObjects["cornerpot1"] = new Cube(
            "cornerpot1",
            gl,
            vec4(0, 0, 0, 1),
            new Transform({ translation: translate(-47, 0, -25), scaling: scalem(6, 3, 6) })
        );

        gameObjects["cornerpot2"] = new Cube(
            "cornerpot2",
            gl,
            vec4(0, 0, 0, 1),
            new Transform({ translation: translate(47, 0, -25), scaling: scalem(6, 3, 6) })
        );

        gameObjects["cornerpot3"] = new Cube(
            "cornerpot3",
            gl,
            vec4(0, 0, 0, 1),
            new Transform({ translation: translate(-47, 0, 25), scaling: scalem(6, 3, 6) })
        );

        gameObjects["cornerpot4"] = new Cube(
            "cornerpot4",
            gl,
            vec4(0, 0, 0, 1),
            new Transform({ translation: translate(47, 0, 25), scaling: scalem(6, 3, 6) })
        );


        gameObjects["pot5"] = new Cube(
            "pot5",
            gl,
            vec4(0.0, 0.0, 0.0, 1.0),
            new Transform({ translation: translate(0, 0, 26.5), scaling: scalem(4, 3, 3) })
        );
        gameObjects["pot6"] = new Cube(
            "pot6",
            gl,
            vec4(0.0, 0.0, 0.0, 1.0),
            new Transform({ translation: translate(0, 0, -26.5), scaling: scalem(4, 3, 3) })
        );

        gameObjects["border1"] = new Cube(
            "border1",
            gl,
            vec4(0.54, 0.26, 0.07, 1.0),
            new Transform({ translation: translate(-24.5, 0, -26.5), scaling: scalem(45, 2, 3) })
        );

        gameObjects["border2"] = new Cube(
            "border2",
            gl,
            vec4(0.54, 0.26, 0.07, 1.0),
            new Transform({ translation: translate(24.5, 0, -26.5), scaling: scalem(45, 2, 3) })
        );

        gameObjects["border3"] = new Cube(
            "border3",
            gl,
            vec4(0.54, 0.26, 0.07, 1.0),
            new Transform({ translation: translate(-24.5, 0, 26.5), scaling: scalem(45, 2, 3) })
        );

        gameObjects["border4"] = new Cube(
            "border4",
            gl,
            vec4(0.54, 0.26, 0.07, 1.0),
            new Transform({ translation: translate(24.5, 0, 26.5), scaling: scalem(45, 2, 3) })
        );

        gameObjects["border5"] = new Cube(
            "border5",
            gl,
            vec4(0.54, 0.26, 0.07, 1.0),
            new Transform({ translation: translate(-48.5, 0, 0), scaling: scalem(3, 2, 49.5) })
        );

        gameObjects["border6"] = new Cube(
            "border6",
            gl,
            vec4(0.54, 0.26, 0.07, 1.0),
            new Transform({ translation: translate(48, 0, 0), scaling: scalem(3, 2, 50) })
        );

        gameObjects["border6"] = new Cube(
            "border6",
            gl,
            vec4(0.54, 0.26, 0.07, 1.0),
            new Transform({ translation: translate(48, 0, 0), scaling: scalem(3, 2, 50) })
        );





        /*         gameObjects["xAxis"] = new Cube(
                    "xAxis",
                    gl,
        
                    vec4(0.0, 0.0, 1.0, 1.0),
                    new Transform({
                        scaling: scalem(1, 0.2, 0.2),
                        translation: translate(0.5, 0, 0)
                    })
                );
        
                gameObjects["yAxis"] = new Cube(
                    "yAxis",
                    gl,
        
                    vec4(0.0, 0.0, 0.0, 1.0),
                    new Transform({ scaling: scalem(0.2, 1, 0.2) })
                );
        
                gameObjects["zAxis"] = new Cube(
                    "zAxis",
                    gl,
                    vec4(1, 0.0, 0.0, 1.0),
        
                    new Transform({
                        scaling: scalem(0.2, 0.2, 1),
                        translation: translate(0, 0, 0.5)
                    })
                ); */


    }
}