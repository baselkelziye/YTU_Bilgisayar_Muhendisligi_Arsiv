import re
import gradio as gr
from transformers import AutoModelForCausalLM, AutoTokenizer



def extract_code_codegen(input_text):
    pattern = r"'''py\n(.*?)'''"
    match = re.search(pattern, input_text, re.DOTALL)
    
    if match:
        return match.group(1)
    else:
        return None  # Return None if no match is found
    
def extract_code_mistral(input_text):
    pattern = r'\[CODE\](.*?)\[/CODE\]'
    match = re.search(pattern, input_text, re.DOTALL)

    if match:
        return match.group(1)
    else:
        return None  # Return None if no match is found

def generate_code(input_text,modelName):
    if(modelName == "codegen-350M"):
        input_ids = codeGenTokenizer(input_text, return_tensors="pt").input_ids
        generated_ids = codeGenModel.generate(input_ids, max_length=128)
        result = codeGenTokenizer.decode(generated_ids[0], skip_special_tokens=True)
        return extract_code_codegen(result)
    elif(modelName == "mistral-7b"):
        input_ids = mistralTokenizer(generate_prompt_mistral(input_text), return_tensors="pt").input_ids
        generated_ids = mistralModel.generate(input_ids, max_length=128)
        result = mistralTokenizer.decode(generated_ids[0], skip_special_tokens=True)
        return extract_code_mistral(result)
    else:
        return None
    
def generate_prompt_mistral(text):
    system_msg = "Below is an instruction that describes a programming task. Write a response code that appropriately completes the request.\n"
    return f"<s>[INST] {system_msg}\n{text} [/INST]"

def respond(message, chat_history, additional_inputs):
    return  f"Here's an example code:\n\n```python\n{generate_code(message,additional_inputs)}\n```" 


codeGenModel = AutoModelForCausalLM.from_pretrained('parsak/codegen-350M-mono-lora-instruction')
mistralModel = AutoModelForCausalLM.from_pretrained('parsak/mistral-code-7b-instruct')
codeGenTokenizer = AutoTokenizer.from_pretrained('Salesforce/codegen-350M-mono')
mistralTokenizer = AutoTokenizer.from_pretrained('parsak/mistral-code-7b-instruct')
codeGenTokenizer.pad_token_id = 0
codeGenTokenizer.padding_side = "left" 


dropdown = gr.Dropdown(label="Models",choices=["codegen-350M", "mistral-7b"], value="codegen-350M")

interface = gr.ChatInterface(respond,
        retry_btn= gr.Button(value="Retry"), 
        undo_btn=None, clear_btn=gr.Button(value="Clear"),
        additional_inputs=[
            dropdown
        ]
        )


if __name__ == "__main__":
    interface.launch()

