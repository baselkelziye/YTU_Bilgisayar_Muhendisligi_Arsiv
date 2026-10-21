# Code Generation with LLMs

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

## Description

Final Report can be accessed from [final_rapor.pdf](<final_rapor.pdf>)

This repository contains the code for our final year project at Yildiz Technical University.

You can find the models in the following links in huggingfaces' model hub:

- [codegen-instruct on HF hub](https://huggingface.co/parsak/codegen-350M-mono-lora-instruction)
- [mistral-code on HF hub](https://huggingface.co/parsak/mistral-code-7b-instruct)
- [phi2-code on HF hub](https://huggingface.co/parsak/phi-2-code-instruct)

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Installation

This repository comes with a utility package [parsakzr/codellm](https://github.com/parsakzr/codellm)

To install and use the project locally, follow these steps:

1. Clone the repository

```bash
git clone [repo-url]
cd [repo-name]
```

2. Install the dependencies

```bash
pip install -r requirements.txt
```

Optional: Also, if you want to run the notebooks, you need to install jupyter notebook.

```bash
pip install jupyter
```

## Usage

The directory structure of the project is as follows:

```bash
.
├── finetuning
│   ├── codegen
│   ├── humaneval
│   └── mbpp
├── evaluation
│   ├── evalanalysis.ipynb
│   ├── CodeGen
│   ├── mistral-code
│   ├── phi2-code
│   └── etc.
└── GUI
    ├── EvalModelOnGradio.ipynb
    ├── run.py
    └── etc.
```

- In the `finetuning` directory, you can find the code for the finetuning of the models. just run the notebooks in Colab, or locally.
- In the `evaluation` directory, you can find the code for the evaluation of the models.
- In the `GUI` directory, you can find the code to run the GUI. You can run the GUI by running the `run.py` file. or use the notebook to run it in Colab.

To run the UI

```bash
cd GUI
pip install -r requirements.txt
python run.py
```

And then go to given URL in your browser.

## Contributing

Contributions are always welcome! Please create a Pull Request to contribute. If you find any bugs, please report them as issues.

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

- GitHub: [parsakzr](https://github.com/parsakzr)

## References

- [Code Generation with LLMs](#)
- [EvalPlus](https://github.com/evalplus/evalplus)
- [CodeAlpaca Dataset](https://github.com/sahil280114/codealpaca)
