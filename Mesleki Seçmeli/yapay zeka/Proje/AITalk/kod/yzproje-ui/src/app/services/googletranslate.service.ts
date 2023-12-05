import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class GoogletranslateService {
  url: string = 'https://translation.googleapis.com/language/translate/v2?key=';
  key: string = 'AIzaSyBPpEqMrD9bZs0FR_MliJpTf3aWs4BcTbM'

  constructor(private httpClient: HttpClient) { }

  translate(text: string, language: string){
    const obj = {
      q: text,
      target: language
    }
    return this.httpClient.post(this.url + this.key, obj)
  }
  
}
