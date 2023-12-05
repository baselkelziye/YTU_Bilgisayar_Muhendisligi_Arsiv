from flask import Flask
from flask import request
from flask_cors import CORS, cross_origin
from export import ExportModel
import requests

app = Flask(__name__)

CORS(app)

export = None

@app.route("/", methods=['POST', 'GET'])
@cross_origin()
def indexRoute():
    return chatFunc("abcabc")

@app.route("/chat", methods=['POST'])
@cross_origin()
def chatRoute():
    url = "https://translation.googleapis.com/language/translate/v2?key=AIzaSyBPpEqMrD9bZs0FR_MliJpTf3aWs4BcTbM"
    try:
        if(request != None and request.json != None and request.json['message'] != None):
            message = request.json['message']
            print(request.json["message"])

            data = {
                'q': message,
                'target':'en'
            }

            response = requests.post(url, data=data)

            if(response.status_code == 200):
                print("response")
                print(response.json())
                print("response data")
                
                translatedMessage = response.json()['data']['translations'][0]['translatedText']
                print(translatedMessage)

                res = export.replyForGui(translatedMessage)
            
            else:
                res ="response error"

    except:
        res ="Sorry. I can't understand you. Please tell me different way. :("


    data = {
        'q': res,
        'target':'tr'
    }

    response = requests.post(url, data=data)
    translatedResponse = response.json()['data']['translations'][0]['translatedText']

    return  {'res': translatedResponse}


def chatFunc(message): 
    return "test response message"

if __name__ == "__main__":
    export = ExportModel(".")
    app.run(port=5001, debug=True)