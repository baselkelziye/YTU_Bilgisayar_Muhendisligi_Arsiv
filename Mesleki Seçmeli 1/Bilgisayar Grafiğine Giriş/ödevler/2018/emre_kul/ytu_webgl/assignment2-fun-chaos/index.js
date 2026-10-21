"use strict"
let gl;

const UNIFORM_LOCATION = {
    model: 0,
    color: 0
};
const SHAPE_COUNT = 50;
const SHAPE_SCALE = vec3(0.1, 0.1, 0.1);
const SHAPES = []

const randomFloat = function(bottom, up){
    return Math.random()*(up-bottom)+bottom;
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
    let i;
    let vertices = [];
    let shape;
    for (i = 0; i < SHAPE_COUNT; i++) {
        if(i%2 == 0){
            shape = createCube();
        }
        else{
            shape = createTetrahedron();
        }
        SHAPES.push({
            translate: vec3(randomFloat(-1.0,1.0), randomFloat(-1.0,1.0), 0.0),
            rotate: vec3(30,0,0),
            scale: SHAPE_SCALE,
            color: vec4(randomFloat(0.0,1.0), randomFloat(0.0,1.0), randomFloat(0.0,1.0), 1.0),
            vertPos: {
                start: vertices.length,
                size: shape.length
            }
        });
        vertices = vertices.concat(shape);
    }
    return vertices;
}

const init = function () {
    let canvas = document.getElementById('gl-canvas');

    gl = WebGLUtils.setupWebGL(canvas);
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
    let modelMtr,i;
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    for (i = 0;i < SHAPES.length;i++) {
        let shape = SHAPES[i];
        modelMtr = createModelMatrix(shape.translate, shape.scale, shape.rotate);
        gl.uniformMatrix4fv(UNIFORM_LOCATION.model, false, flatten(modelMtr));
        gl.uniform4fv(UNIFORM_LOCATION.color, shape.color);
        gl.drawArrays(gl.TRIANGLES, shape.vertPos.start, shape.vertPos.size);
        SHAPES[i].rotate[1] += Math.floor(randomFloat(0,10));
        SHAPES[i].rotate[1] %= 360;
    }
    requestAnimFrame(render);
}

window.onload = init;