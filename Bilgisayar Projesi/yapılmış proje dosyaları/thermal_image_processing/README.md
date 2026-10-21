# Thermal-Image-Processing
This is a project done in the context of a Semester Project in Yildiz Technical University. The project details can be found in the details.
Main objective is to compare AI models on thermal image processing based on their structure. Transformer based vs. YOLO

# Disclaimer
For educational purposes (restrictions, per se) as it stands,  I can not share the database's link. Please contact me to acquire the datas, via: tekinalperen017@gmail.com. 

# Example Images (for all the examples please refer to the Makale.pdf)

![Input](./images/example_input.jpg)
![Output](./images/example_output.png)


## Requirements
IDE: VSCode (or any Python environment)
Data Annotation: RoboFlow Annotate, LabelStudio
To run the DEMO, a runtime environment and a package manager are required, provided by Node.js.
Programming Language: ^Python 3.12
To compile OpenCV wheels without issues: MS C++ Build Tools
To ensure proper execution of FFmpeg DLLs within OpenCV: FFmpeg.

## How to run

---

To run the project, the following bash commands must be executed in separate terminals (one for the backend and one for the frontend) in order. Be sure to create separate folders for each side and navigate into the appropriate folder before running the commands.

---

**Backend:**

1.

```
python -m venv .venv
```

2.

```
.venv\Scripts\activate
```

(you may need to run `Set-ExecutionPolicy -Scope CurrentUser RemoteSigned`)

3.

```
python -m pip install --upgrade pip
```

4.

```
pip install fastapi uvicorn[standard] opencv-python ultralytics numpy python-multipart
```

5.

```
pip install pycocotools
```

6.

```
copy . ./main.py
```

#### the `main.py` file provided

7.

```
git clone https://github.com/facebookresearch/detr.git
```

8.

```
copy . ./detr\engine.py
```

#### the `engine.py` file provided

9.

```
mkdir static
```

10.

```
copy ..\best.pt .
```

#### the trained YOLO model

11.

```
copy ..\checkpoint.pth .
```

#### the trained DETR model

12.

```
uvicorn main:app --reload --host 0.0.0.0 --port 8000
```

#### → Serves the `static` folder at `localhost:8000`.

---

### **In a separate terminal**
### **Frontend:**

1.

```
npx create-next-app@latest front --ts --tailwind --eslint --app --src-dir --import-alias "@/*"
```

2.

```
npm i lucide-react framer-motion @radix-ui/react-progress class-variance-authority
```

3.

```
npx shadcn-ui@latest init -y
```

4.

```
copy ..\page.tsx src\app\page.tsx
```

#### the provided `page.tsx` file

5.

```
xcopy ..\components src\components /E /I
```

#### the provided `components` folder

6.

```
npm run dev
```

#### → Runs at `localhost:3000`
