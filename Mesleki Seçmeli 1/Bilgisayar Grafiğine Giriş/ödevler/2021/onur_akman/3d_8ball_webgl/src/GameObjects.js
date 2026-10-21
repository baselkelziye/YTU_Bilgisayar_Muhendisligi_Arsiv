window.onload = function init() {
  Mouse.reset();
  const [gl, aspect] = setupWebGL();
  const hier = new Hierarchy(gl);
  gui = new GUI(aspect);
  ///const shader = .... give shader objects to gameobjecs explicitly
  start(hier.gameObjects);
  render(gl, hier.gameObjects, gui);
};

//--------------------------------------------------------------------------------------------------------------------------------------------------

//// base class for game objects
class GameObject {
  constructor(
    name,
    gl,
    pointsArray,
    colorsArray,
    transform,
    collider = undefined,
    script = undefined,
    vertexShader = "",
    fragmentShader = ""
  ) {
    //// WebGL rendering context
    this.gl = gl;

    //// name of this object. this must be unique.
    this.name = name;

    //// components go here
    this.component = {};

    //// the script component
    this.component.script = script;

    //// current object transform
    this.transform = transform;

    //// camera settings
    this.viewMatrix = mat4();
    this.projectionMatrix = mat4();

    //// collisions
    if (collider) {
      this.collider = collider;
      this.collider.gameObject = this;
      this.collidesWith = [];
    }

    //// shaders and the program object
    if (vertexShader === "") this.createVertexShader();
    else this.vertexShader = vertexShader;

    if (fragmentShader === "") this.createFragmentShader();
    else this.fragmentShader = fragmentShader;

    this.program = this.createProgram();

    //// buffers and gpu data
    this.colorsArray = colorsArray;
    this.pointsArray = pointsArray;
    this.initAttributeBuffers();
  }

  _compileShader(type, src) {
    const shader = this.gl.createShader(type, src);
    this.gl.shaderSource(shader, src);
    this.gl.compileShader(shader);
    if (!this.gl.getShaderParameter(shader, this.gl.COMPILE_STATUS)) {
      console.error(this.gl.getShaderInfoLog(shader));
    }
    return shader;
  }

  //// prepares a program object from shaders
  createProgram() {
    const vertexShader = this._compileShader(
      this.gl.VERTEX_SHADER,
      this.vertexShader
    );
    const fragmentShader = this._compileShader(
      this.gl.FRAGMENT_SHADER,
      this.fragmentShader
    );

    this.program = this.gl.createProgram();
    this.gl.attachShader(this.program, vertexShader);
    this.gl.attachShader(this.program, fragmentShader);
    this.gl.linkProgram(this.program);
    if (!this.gl.getProgramParameter(this.program, this.gl.LINK_STATUS)) {
      console.error(this.gl.getProgramInfoLog(this.program));
    }
    return this.program;
  }

  detectsCollisionWith(other) {
    if (!this.collider) return false;
    if (!other.collider) return false;
    if (this.collider.detectsCollisionWith(other.collider)) return true;

    return false;
  }

  createVertexShader() {
    this.vertexShader = ` 
      attribute  vec4 vPosition;
      attribute  vec4 vColor;
      varying vec4 fColor;

      uniform mat4 modelViewProjectionMatrix;

      void main()
      {
        gl_Position = modelViewProjectionMatrix * vPosition;
        fColor = vColor;
      }
    `;
    return this.vertexShader;
  }

  createFragmentShader() {
    this.fragmentShader = `
      #ifdef GL_ES
      precision highp float;
      #endif


      varying vec4 fColor;

      void
      main()
      {
          gl_FragColor = fColor;
      }
    `;
    return this.fragmentShader;
  }

  initAttributeBuffers() {
    //// color attribute
    this.cBuffer = this.gl.createBuffer();
    this.gl.bindBuffer(this.gl.ARRAY_BUFFER, this.cBuffer);
    this.gl.bufferData(
      this.gl.ARRAY_BUFFER,
      flatten(this.colorsArray),
      this.gl.STATIC_DRAW
    );
    this.vColor = this.gl.getAttribLocation(this.program, "vColor");

    //// position attribute
    this.vBuffer = this.gl.createBuffer();
    this.gl.bindBuffer(this.gl.ARRAY_BUFFER, this.vBuffer);
    this.gl.bufferData(
      this.gl.ARRAY_BUFFER,
      flatten(this.pointsArray),
      this.gl.STATIC_DRAW
    );
    this.vPosition = this.gl.getAttribLocation(this.program, "vPosition");

    //// Uniform Locations
    this.modelViewProjectionMatrixLoc = this.gl.getUniformLocation(
      this.program,
      "modelViewProjectionMatrix"
    );
  }

  draw() {
    //// switch to this objects program
    this.gl.useProgram(this.program);

    //// color attribute
    this.gl.bindBuffer(this.gl.ARRAY_BUFFER, this.cBuffer);
    this.gl.vertexAttribPointer(this.vColor, 4, this.gl.FLOAT, false, 0, 0);
    this.gl.enableVertexAttribArray(this.vColor);

    //// position attribute
    this.gl.bindBuffer(this.gl.ARRAY_BUFFER, this.vBuffer);
    this.gl.vertexAttribPointer(this.vPosition, 4, this.gl.FLOAT, false, 0, 0);
    this.gl.enableVertexAttribArray(this.vPosition);

    //// compute modelViewProjectionMatrix
    const modelViewProjectionMatrix = mult(
      this.projectionMatrix,
      mult(this.viewMatrix, this.transform.modelMatrix())
    );
    //// gpu modelViewProjectionMatrix
    this.gl.uniformMatrix4fv(
      this.modelViewProjectionMatrixLoc,
      false,
      flatten(modelViewProjectionMatrix)
    );

    //// draw
    this.gl.drawArrays(this.gl.TRIANGLES, 0, this.pointsArray.length);

    //// disable vaa's
    this.gl.disableVertexAttribArray(this.vColor);
    this.gl.disableVertexAttribArray(this.vPosition);
  }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------


class Cube extends GameObject {
  constructor(name, gl, color, transform) {
    const [pointsArray, colorsArray] = cubePointsAndColors(color);
    const collider = new NaiveBoxCollider(cubeVertices());
    super(name, gl, pointsArray, colorsArray, transform, collider);
  }
}

class Ball extends GameObject {
  constructor(name, gl, color, transform) {
    const [pointsArray, colorsArray] = ballPointsAndColors(color);
    const collider = new NaiveBoxCollider(cubeVertices());
    super(name, gl, pointsArray, colorsArray, transform, collider);
  }
}

class PoolTable extends GameObject {
  constructor(name, gl, color, transform) {
    const [pointsArray, colorsArray] = tablePointsAndColors(color);
    const collider = new NaiveBoxCollider(cubeVertices());
    super(name, gl, pointsArray, colorsArray, transform, collider);
  }
}

class Leg extends GameObject {
  constructor(name, gl, color, transform) {
    const [pointsArray, colorsArray] = legPointsAndColors(color);
    const collider = new NaiveBoxCollider(cubeVertices());
    super(name, gl, pointsArray, colorsArray, transform, collider);
  }
}

class Square extends GameObject {
  constructor(name, gl, color, transform) {
    const [pointsArray, colorsArray] = squarePointsAndColors(color);
    //const collider = new NaiveBoxCollider(cubeVertices());
    super(name, gl, pointsArray, colorsArray, transform);
  }
}

class TableFace extends GameObject {
  constructor(name, gl, color, transform) {
    const [pointsArray, colorsArray] = facePointsAndColors(color);
    //const collider = new NaiveBoxCollider(cubeVertices());
    super(name, gl, pointsArray, colorsArray, transform);
  }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

//// time functionality
class GameTime {
  static deltaTime = 0;
  static timestamp = -1;

  static updateTimestamp(timestamp) {
    if (GameTime.timestamp < 0) GameTime.timestamp = timestamp;
    GameTime.deltaTime = timestamp - GameTime.timestamp;
    GameTime.timestamp = timestamp;
  }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------


function start(gameObjects) {
  for (const gameObject of Object.values(gameObjects)) {
    if (gameObject.component.script) gameObject.component.script.start();
  }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

function render(gl, gameObjects, gui, timestamp) {
  ////// GameEngine related
  //// update game time
  if (timestamp) GameTime.updateTimestamp(timestamp);

  //// detect all collisions
  const objects = Object.values(gameObjects);
  for (const object of objects) object.collidesWith = [];
  for (let i = 0; i < objects.length; i++) {
    const current = objects[i];
    for (let j = i + 1; j < objects.length; j++) {
      const other = objects[j];
      if (
        current.detectsCollisionWith(other) ||
        other.detectsCollisionWith(current)
      ) {
        current.collidesWith.push(other);
        other.collidesWith.push(current);
      }
    }
  }

  //// handle all collisions
  for (const gameObject of Object.values(gameObjects)) {
    if (gameObject.component.script) {
      for (const other of gameObject.collidesWith) {
        gameObject.component.script.onCollision(other);
      }
    }
  }

  //// update all objects
  for (const gameObject of Object.values(gameObjects)) {
    if (gameObject.component.script) gameObject.component.script.update();
  }

  ////// WebGL related
  //// clear the background
  gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

  //// camera settings
  eye = sphericalEye(
    gui.radius.slider.value,
    gui.theta.slider.value * (Math.PI / 180),
    gui.phi.slider.value * (Math.PI / 180)
  );
  const viewMatrix = lookAt(eye, at, up);
  const projectionMatrix = perspective(
    90, //  gui.fovy.slider.value,
    1.00, //  gui.aspect.slider.value,
    0.1, //  gui.near.slider.value,
    1000 //  gui.far.slider.value
  );

  //// draw all objects
  for (const gameObject of Object.values(gameObjects)) {
    gameObject.viewMatrix = viewMatrix;
    gameObject.projectionMatrix = projectionMatrix;
    gameObject.draw();
  }

  //// call self for recursion
  requestAnimFrame(timestamp => render(gl, gameObjects, gui, timestamp));
}

function setupWebGL() {
  const canvas = document.getElementById("canvas1");
  const gl = WebGLUtils.setupWebGL(canvas);
  if (!gl) {
    console.error("Could not set up WebGL");
  }
  gl.viewport(0, 0, canvas.width, canvas.height);
  aspect = canvas.width / canvas.height;
  gl.clearColor(1.0, 1.0, 1.0, 1.0);
  gl.enable(gl.DEPTH_TEST);
  return [gl, aspect];
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

//// SHOOT WEB Components
class Slider {
  constructor(id, min, max, step, value, divId) {
    //// create - get elements
    this.div = document.getElementById(divId);
    this.labelSpan = document.createElement("span");
    this.slider = document.createElement("input");

    //// set up elements
    this.labelSpan.setAttribute("id", id + "LabelSpan");
    this.labelSpan.innerHTML = value;

    this.slider.setAttribute("type", "range");
    this.slider.setAttribute("min", min);
    this.slider.setAttribute("max", max);
    this.slider.setAttribute("step", step);
    this.slider.setAttribute("id", id);
    this.slider.setAttribute("value", value);
    this.slider.oninput = function (event) {
      document.getElementById(id + "LabelSpan").innerHTML = event.target.value;
    };

    //// build the hierarchy
    this.div.appendChild(document.createTextNode(this.slider.id + " "));
    this.div.appendChild(document.createTextNode(this.slider.min));
    this.div.appendChild(this.slider);
    this.div.appendChild(document.createTextNode(this.slider.max + " ("));
    this.div.appendChild(this.labelSpan);
    this.div.appendChild(document.createTextNode(")"));
  }
}

class Text {
  constructor(text, divId) {
    document
      .getElementById(divId)
      .appendChild(
        document
          .createElement("span")
          .appendChild(document.createTextNode(text))
      );
  }
}
class Br {
  constructor(divId) {
    document.getElementById(divId).appendChild(document.createElement("br"));
  }
}
class Hr {
  constructor(divId) {
    document.getElementById(divId).appendChild(document.createElement("hr"));
  }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

class GUI {
  constructor(aspect) {
    new Hr("cam-props");
    new Text("Camera Position", "cam-props");
    new Br("cam-props");
    this.radius = new Slider("radius", 40, 100, 1, 17, "cam-props");
    new Br("cam-props");
    this.theta = new Slider("theta", 20, 180, 1, 51, "cam-props");
    new Br("cam-props");
    this.phi = new Slider("phi", 20, 180, 1, 83, "cam-props");

    //new Hr("cam-props");
    //new Text("Camera Projection", "cam-props");
    //new Br("cam-props");
    //this.near = new Slider("near", 0.01, 3, 0.01, 0.1, "cam-props");
    //new Br("cam-props");
    //this.far = new Slider("far", 3, 1000, 1, 1000, "cam-props");
    //new Br("cam-props");
    //this.fovy = new Slider("fovy", 10, 120, 1, 90, "cam-props");
    //new Br("cam-props");
    //this.aspect = new Slider("aspect", 0.01, 10, 0.1, aspect, "cam-props");
    //new Hr("cam-props");

  }
}


