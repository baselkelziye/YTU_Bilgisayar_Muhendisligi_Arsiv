/// a class that represents the gameobject transform matrices
class Transform {
    constructor({
        scaling = mat4(),
        rotation = mat4(),
        translation = mat4()
    } = {}) {
        this.scaling = scaling;
        this.rotation = rotation;
        this.translation = translation;
    }
    modelMatrix() {
        return mult(this.translation, mult(this.rotation, this.scaling));
    }
}

class NaiveCollider {
    constructor(vertices) {
        this.vertices = vertices;
        this.gameObject = null; // make sure this is assigned after instantiation
    }

    detectsCollisionWith(other) {
        // iterate over vertices of the other, if any vertice is inside
        // then we have a collision
        const otherVertices = other.transformedVertices();
        const inverseTransform = inverse4(this.gameObject.transform.modelMatrix());

        for (const otherVertice of otherVertices) {
            if (this.includes(mult(inverseTransform, otherVertice))) return true;
        }
        return false;
    }

    transformedVertices() {
        const vertices = [];
        const modelMatrix = this.gameObject.transform.modelMatrix();
        for (const vertice of this.vertices) {
            vertices.push(mult(modelMatrix, vertice));
        }
        return vertices;
    }
}

class NaiveBoxCollider extends NaiveCollider {
    constructor(vertices) {
        super(vertices);
    }
    includes(v) {
        const x = v[0];
        const y = v[1];
        const z = v[2];
        if (-0.5 <= x && x <= 0.5 && 0 <= y && y <= 1 && -0.5 <= z && z <= 0.5) {
            return true;
        }
        return false;
    }
}

function mults(scalar, transform) {
    return mult(scalem(scalar, scalar, scalar), transform);
}