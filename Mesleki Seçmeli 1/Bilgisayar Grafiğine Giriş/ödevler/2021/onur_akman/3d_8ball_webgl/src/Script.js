class Script {
    constructor() {
        this.gameObject = null;
        this.gameObjects = {};
    }
    start() { }
    update() { }
    onCollision() { }
}



class CubeScript extends Script {
    start() {
        this.xpower = 0;
        this.zpower = 0;
        this.ypower = 0;
        this.isBlack = false;
        this.xturned = true;
        this.zturned = true;
        this.moving = false;
    }

    update() {
        if ((this.xpower != 0) || (this.zpower != 0) || (this.ypower != 0)) {
            this.moving = true;
            this.gameObject.transform.rotation = mult(
                rotateY(1),
                this.gameObject.transform.rotation
            );

            const velocity = [this.xpower / 1000, this.ypower / 100, this.zpower / 1000];
            const dt = GameTime.deltaTime;
            const scaledVelocity = scale(dt, velocity);
            const changeMatrix = translate(scaledVelocity);
            this.gameObject.transform.translation = mult(
                changeMatrix,
                this.gameObject.transform.translation
            );

            this.xpower = this.xpower * 0.98
            this.zpower = this.zpower * 0.98
            this.ypower = this.ypower * 0.98
        } else this.moving = false;
    }

    onCollision(other) {
        if ((other.name.includes("Cube"))) {
            this.xpower = this.xpower / 3;
            this.zpower = this.zpower / 3;
            other.component.script.xpower += this.xpower * 2;
            other.component.script.zpower += this.zpower * 2;
        }
        else if (other.name.includes("pot")) {
            this.ypower = -5;
            this.zpower = 0;
            this.xpower = 0;
            console.log("Ball in the pot!");
            if (this.isBlack) location.reload();
        } else if ((other.name === "border1") || (other.name === "border2") || (other.name === "border3") || (other.name === "border4")) {
            this.zpower = -this.zpower;
        }
        else if ((other.name === "border5") || (other.name === "border6")) {
            this.xpower = -this.xpower;
        }
    }
}



class WhiteCubeScript extends Script {
    start() {
        this.initialTranslation = this.gameObject.transform.translation;
        this.xpower = 0;
        this.ypower = 0;
        this.zpower = 0;
        this.xturned = true;
        this.zturned = true;
        this.maxPower = 100;
        this.moving = false;
    }

    update() {
        if ((Keyboard.isPressing) && (Keyboard.key === "8")) {
            this.zpower -= 2;
            if (this.zpower <= -this.maxPower) this.zpower = -this.maxPower;
        }
        else if ((Keyboard.isPressing) && (Keyboard.key === "2")) {
            this.zpower += 2;
            if (this.zpower > this.maxPower) this.zpower = this.maxPower;
        }
        else if ((Keyboard.isPressing) && (Keyboard.key === "4")) {
            this.xpower -= 2;
            if (this.xpower <= -this.maxPower) this.power = -this.maxPower;
        }
        else if ((Keyboard.isPressing) && (Keyboard.key === "6")) {
            this.xpower += 2;
            if (this.xpower > this.maxPower) this.xpower = this.maxPower;
        }
        else if ((Keyboard.key === "s")) {

            if ((this.xpower != 0) || (this.zpower != 0)) this.moving = true;
            else this.moving = false;

            this.gameObject.transform.rotation = mult(
                rotateY(1),
                this.gameObject.transform.rotation
            );

            const velocity = [this.xpower / 1000, this.ypower / 100, this.zpower / 1000];
            const dt = GameTime.deltaTime;
            const scaledVelocity = scale(dt, velocity);
            const changeMatrix = translate(scaledVelocity);
            this.gameObject.transform.translation = mult(
                changeMatrix,
                this.gameObject.transform.translation
            );

            const t = this.gameObject.transform.translation;
            const x = t[0][3];
            const y = t[1][3];
            const z = t[2][3];
            this.xpower = this.xpower * 0.98
            this.zpower = this.zpower * 0.98
            this.ypower = this.ypower * 0.98
            whiteBallPosition = vec3(x, y, z);
        }
    }

    onCollision(other) {
        if ((other.name.includes("Cube"))) {
            this.xpower = this.xpower / 3;
            this.zpower = this.zpower / 3;
            other.component.script.xpower += this.xpower * 2;
            other.component.script.zpower += this.zpower * 2;
        }
        else if (other.name.includes("pot")) {
            this.ypower = -5;
            this.zpower = 0;
            this.xpower = 0;
            console.log("Ball in the pot!");
        } else if ((other.name === "border1") || (other.name === "border2") || (other.name === "border3") || (other.name === "border4")) {
            this.zpower = -this.zpower;
        }
        else if ((other.name === "border5") || (other.name === "border6")) {
            this.xpower = -this.xpower;
        }
    }
}