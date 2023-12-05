import { Component } from '@angular/core';
import { FormControl, Validators } from '@angular/forms';
import { Title } from '@angular/platform-browser';

@Component({
  selector: 'app-chatbot-settings',
  templateUrl: './chatbot-settings.component.html',
  styleUrls: ['./chatbot-settings.component.css']
})
export class ChatbotSettingsComponent {
  langModels: any[] = [{key: 'prepared', name: 'Prepared Dataset Model'}, {key: 'reddit', name: 'Reddit Dataset Model'}];
  selectedModel!: string | null;
  modelSelectControl!: FormControl;
  
  constructor(private titleService: Title){}

  ngOnInit(){
    this.titleService.setTitle("Settings | TechTalk");
    this.selectedModel = localStorage.getItem("model");
    this.modelSelectControl = new FormControl(this.selectedModel, {validators: [Validators.required]});
  }

  onModelSelectChange(){
    if(this.modelSelectControl.valid)
      localStorage.setItem("model", this.modelSelectControl.value);
  }

}
