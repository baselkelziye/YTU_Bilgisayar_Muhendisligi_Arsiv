import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { ChatbotAnalytcsComponent } from './chatbot-analytcs/chatbot-analytcs.component';
import { ChatbotMainComponent } from './chatbot-main/chatbot-main.component';
import { ChatbotSettingsComponent } from './chatbot-settings/chatbot-settings.component';

const routes: Routes = [
  {
    path: '',
    component: ChatbotMainComponent,
  },
  {
    path: "chat",
    component: ChatbotMainComponent
  },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
