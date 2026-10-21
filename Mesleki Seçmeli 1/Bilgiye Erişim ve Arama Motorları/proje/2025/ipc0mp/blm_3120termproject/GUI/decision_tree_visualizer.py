import uuid

decision_tree_visualizer_js = """
window.initTree = function(id) {
    const viewport = document.getElementById('vp-' + id);
    const content = document.getElementById('ct-' + id);
    if (!viewport || !content) return;

    let scale = 1, tx = 0, ty = 0;
    const update = () => content.style.transform = `translate(${tx}px, ${ty}px) scale(${scale})`;

    const zoomAtPointer = (e, factor) => {
        if (e.preventDefault) e.preventDefault();

        const rect = viewport.getBoundingClientRect();
        const mouseX = e.clientX - rect.left;
        const mouseY = e.clientY - rect.top;

        // calculate the point under the cursor
        const worldX = (mouseX - tx) / scale;
        const worldY = (mouseY - ty) / scale;

        const newScale = scale * factor;
        if (newScale < 0.50 || newScale > 50) return; // Boundary check
        scale = newScale;

        // recalculate translation so the world point stays under the cursor
        tx = mouseX - worldX * scale;
        ty = mouseY - worldY * scale;

        update();
    };

    document.getElementById('in-' + id).onclick = () => {
        const rect = viewport.getBoundingClientRect();
        zoomAtPointer({
            clientX: rect.left + rect.width / 2,
            clientY: rect.top + rect.height / 2
        }, 1.2);
    };

    document.getElementById('out-' + id).onclick = () => {
        const rect = viewport.getBoundingClientRect();
        zoomAtPointer({
            clientX: rect.left + rect.width / 2,
            clientY: rect.top + rect.height / 2
        }, 0.8);
    };

    // wheel trap
    viewport.addEventListener('wheel', (e) => {
        e.preventDefault();
        const factor = e.deltaY > 0 ? 0.9 : 1.1;
        zoomAtPointer(e, factor);
    }, { passive: false });


    // panning
    let isDragging = false, lastX, lastY;
    viewport.onmousedown = (e) => { isDragging = true; lastX = e.clientX; lastY = e.clientY; };
    window.addEventListener('mousemove', (e) => {
        if (!isDragging) return;
        tx += e.clientX - lastX; ty += e.clientY - lastY;
        lastX = e.clientX; lastY = e.clientY;
        update();
    });

    window.addEventListener('mouseup', () => isDragging = false);
};
"""

def get_interactive_tree_html(svg_string):
    uid = str(uuid.uuid4())[:8]
    svg_clean = svg_string.replace('width="', 'data-w="').replace('height="', 'data-h="')

    return f"""
    <div class="tree-container" style="position: relative; border: 1px solid #444; background: white; height: 600px; overflow: hidden; cursor: grab;">
        <div style="position: absolute; top: 10px; left: 10px; z-index: 10;">
            <button id="in-{uid}">+</button>
            <button id="out-{uid}">-</button>
        </div>

        <div id="vp-{uid}" style="width: 100%; height: 100%; cursor: grab;">
            <div id="ct-{uid}" style="transform-origin: 0 0;">
                {svg_clean}
            </div>
        </div>

        <img src='x' onerror="initTree('{uid}')" style="display:none;"/>
    </div>
    """
