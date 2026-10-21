"use strict"
let gl;

const UNIFORM_LOCATION = {
    model: 0,
    color: 0
};

const SHAPE = {
    cube: {
        translate: vec3(-0.6, 0.0, 0.0),
        scale: vec3(0.2, 0.2, 0.2),
        rotate: vec3(30, 0, 0),
        color: vec4(1.0, 0.0, 0.0, 1.0),
        vertPos: {
            start: 0,
            size: 0
        }
    },
    tetrahedron: {
        translate: vec3(0.6, 0.0, 0.0),
        scale: vec3(0.2, 0.2, 0.2),
        rotate: vec3(30, 0, 0),
        color: vec4(1.0, 1.0, 0.0, 1.0),
        vertPos: {
            start: 0,
            size: 0
        }
    }
}

const createTetrahedron = function () {
    let i, tetrahedronVertices = [];
    const tetrahedronCords = [
        vec4(1.0, 1.0, 1.0),//right top front
        vec4(-1.0, -1.0, 1.0),//left bottom front
        vec4(-1.0, 1.0, -1.0),//left top back
        vec4(1.0, -1.0, -1.0)//right bottom back
    ];
    const tetrahedronIndices = [
        0, 1, 2,
        0, 2, 3,
        0, 1, 3,
        1, 2, 3
    ];
    for (i = 0; i < tetrahedronIndices.length; i++) {
        tetrahedronVertices.push(tetrahedronCords[tetrahedronIndices[i]]);
    }
    return tetrahedronVertices;
}

const createCube = function () {
    let i, cubeVertices = [];
    const cubeCords = [
        vec4(-1, -1, 1, 1),
        vec4(-1, 1, 1, 1),
        vec4(1, 1, 1, 1),
        vec4(1, -1, 1, 1),
        vec4(-1, -1, -1, 1),
        vec4(-1, 1, -1, 1),
        vec4(1, 1, -1, 1),
        vec4(1, -1, -1, 1)
    ];
    const cubeIndices = [
        //a, b, c, a, c, d
        1, 0, 3, 1, 3, 2,
        2, 3, 7, 2, 7, 6,
        3, 0, 4, 3, 4, 7,
        6, 5, 1, 6, 1, 2,
        4, 5, 6, 4, 6, 7,
        5, 4, 0, 5, 0, 1
    ];

    for (i = 0; i < cubeIndices.length; ++i) {
        cubeVertices.push(cubeCords[cubeIndices[i]]);
    }

    return cubeVertices;
}

const createModelMatrix = function (t, s, r) {
    let rotationMtr;
    let translateMtr = translate(t);
    let scaleMtr = scalem(s);

    rotationMtr = rotate(r[0], vec3(1, 0, 0));
    rotationMtr = mult(rotationMtr, rotate(r[1], vec3(0, 1, 0)));
    rotationMtr = mult(rotationMtr, rotate(r[2], vec3(0, 0, 1)));//useless

    return mult(rotationMtr, mult(translateMtr, scaleMtr));
}

const createScene = function () {
    let cube = createCube();
    let tetrahedron = createTetrahedron();

    SHAPE.cube.vertPos = {
        start: 0,
        size: cube.length
    }

    SHAPE.tetrahedron.vertPos = {
        start: cube.length,
        size: tetrahedron.length
    }
    return cube.concat(tetrahedron);
}

const init = function () {
    let canvas = document.getElementById('gl-canvas');

    canvas.addEventListener("mousedown", detectShapeByClickEvent);

    gl = WebGLUtils.setupWebGL(canvas, { preserveDrawingBuffer: true });
    if (!gl)
        alert("Webgl isn't avaliable!");

    gl.viewport(0, 0, canvas.width, canvas.height);
    gl.clearColor(1.0, 1.0, 1.0, 1.0);
    gl.enable(gl.DEPTH_TEST);

    const program = initShaders(gl, 'vertex-shader', 'fragment-shader');
    gl.useProgram(program);
    let vertices = createScene();

    // Load the data into the GPU
    const bufferId = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, bufferId);
    gl.bufferData(gl.ARRAY_BUFFER, flatten(vertices), gl.STATIC_DRAW);

    // Associate out shader variables with our data buffer
    const vPos = gl.getAttribLocation(program, "vPosition");
    gl.vertexAttribPointer(vPos, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vPos);

    UNIFORM_LOCATION.model = gl.getUniformLocation(program, "uModel");
    UNIFORM_LOCATION.color = gl.getUniformLocation(program, 'uColor');

    render();
}

const render = function () {
    let modelMtr;
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    //draw cube
    modelMtr = createModelMatrix(SHAPE.cube.translate, SHAPE.cube.scale, SHAPE.cube.rotate);
    gl.uniformMatrix4fv(UNIFORM_LOCATION.model, false, flatten(modelMtr));
    gl.uniform4fv(UNIFORM_LOCATION.color, SHAPE.cube.color);
    gl.drawArrays(gl.TRIANGLES, SHAPE.cube.vertPos.start, SHAPE.cube.vertPos.size);

    //draw tetrahedron
    modelMtr = createModelMatrix(SHAPE.tetrahedron.translate, SHAPE.tetrahedron.scale, SHAPE.tetrahedron.rotate);
    gl.uniformMatrix4fv(UNIFORM_LOCATION.model, false, flatten(modelMtr));
    gl.uniform4fv(UNIFORM_LOCATION.color, SHAPE.tetrahedron.color);
    gl.drawArrays(gl.TRIANGLES, SHAPE.tetrahedron.vertPos.start, SHAPE.tetrahedron.vertPos.size);

    SHAPE.cube.rotate[1] += 1;
    SHAPE.cube.rotate[1] %= 360;

    SHAPE.tetrahedron.rotate[1] += 1;
    SHAPE.tetrahedron.rotate[1] += 360;

    requestAnimFrame(render);
}

const detectShapeByClickEvent = function (e) {
    let mouseX = e.pageX - gl.canvas.offsetLeft;
    let mouseY = e.pageY - gl.canvas.offsetTop;
    let pixels = new Uint8Array(4);
    gl.readPixels(mouseX, gl.drawingBufferHeight - mouseY, 1, 1, gl.RGBA, gl.UNSIGNED_BYTE, pixels);
    if (pixels[0] === SHAPE.cube.color[0] * 255 &&
        pixels[1] === SHAPE.cube.color[1] * 255 &&
        pixels[2] === SHAPE.cube.color[2] * 255) {
        alert("Hi I am Cube");
        console.log("Hi I am Cube");
    }
    else if (pixels[0] === SHAPE.tetrahedron.color[0] * 255 &&
        pixels[1] === SHAPE.tetrahedron.color[1] * 255 &&
        pixels[2] === SHAPE.tetrahedron.color[2] * 255) {
        alert("Hi I am Tetrahedron!");
        console.log("Hi I am Tetrahedron!");
    }
}

window.onload = init;