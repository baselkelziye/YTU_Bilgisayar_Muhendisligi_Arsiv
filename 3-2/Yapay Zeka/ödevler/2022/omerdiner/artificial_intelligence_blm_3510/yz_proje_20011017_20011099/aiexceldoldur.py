import openpyxl
import os
import time
import google.generativeai as genai

# pip install google-generativeai

# https://aistudio.google.com/app/apikey

api_k = 'AIzaSyCBhxLCrsVbBmnJmp4SmCPaj_AnejLjjyI'

os.environ[api_k] = api_k
genai.configure(api_key=api_k)




#text1="generate me a rock song. make it sound like a song from the 80s. length: 200-250 characters. language: english"
#text2="Write me a rock song. Genre: rock. make me feel like i am in a rock concert.   length: 150-250 character. language: english"
#text3="generate me a rock song lyrics. example artist: queen It should be in English and approximately 200 characters long."
#text4="i want a rock song. create me a lyrics. make it sound like a song from the 70s. length: 200-300 characters. language: english"
#text5="i am a rock singer. i want to sing a song.i like the beatles create me a rock song. length: 200-300 characters. language: english"


text6="generate me a pop song. make it sound like a song from the 2010s. length: 200-250 characters. language: english"
text7="Write me a pop song. Genre: pop. make me feel like i am in a pop concert. enjoying my life  length: 150-250 character. language: english"
text8="generate me a pop song lyrics. example artist: lady gaga It should be in English and approximately 200 characters long."
text9="i want a pop song. create me a lyrics. a song from the 2000s. length: 200-300 characters. language: english"
text10="i am a pop singer. i want to sing a song.i like the justin bieber create me a pop song. length: 200-300 characters. language: english"


prompts = [text6, text7, text8, text9, text10]

def main():
    response_array = []

    model = genai.GenerativeModel('gemini-pro')



    for i in range(250):

        text = prompts[i % len(prompts)]
        try:
            #1 saniye bekleme
            time.sleep(1)
            response = model.generate_content(text)
            response_array.append(response.text)
        except:
            print("Hata oluştu. Devam ediliyor. i deger : ", i)



       # print("Cevap: ", response.text)
       # time.sleep(1)

    #print(response_array)#


    #response arrayini excel dosyasına yazdırma
    wb = openpyxl.Workbook()
    sheet = wb.active
    sheet.title = "Sheet1"
    sheet["A1"] = "Pop Lyrics"
    for i in range(len(response_array)):
        sheet["A" + str(i + 2)] = response_array[i]
    wb.save("pop2.xlsx")


    print("Excel dosyası oluşturuldu.")



if __name__ == "__main__":
    main()