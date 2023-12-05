import { AfterViewInit, Component, ElementRef, ViewChild } from '@angular/core';
import { MatDrawer } from '@angular/material/sidenav';
import { Title } from '@angular/platform-browser';
import { ChatbotService } from '../services/chatbot.service';
import { Observable, map, isObservable} from 'rxjs';
import { FormControl } from '@angular/forms';
import { GoogletranslateService } from '../services/googletranslate.service';

@Component({
  selector: 'app-chatbot-main',
  templateUrl: './chatbot-main.component.html',
  styleUrls: ['./chatbot-main.component.css'],
  providers: [ChatbotService] 
})
export class ChatbotMainComponent implements AfterViewInit {
  openSidenav: boolean = true;
  messageRes$: Observable<any> | undefined;
  messageController: FormControl = new FormControl();
  messages: any[] = [];
  resHasError: boolean = true;
  translateObservable$ : Observable<any> | undefined;
  
  constructor(private titleService: Title, private chatService: ChatbotService, private translateService: GoogletranslateService){}

  ngOnInit(){
    this.titleService.setTitle("AITalk | Chat");
    this.messages.unshift({sent: false, message: this.chatService.postMessage('hi').pipe(map(element => element.res))});
  }


  ngAfterViewInit(): void {
  }

  onDrawerToggle(){
    const classList = document.getElementById('mat-icon-drawer-toggle')?.classList;
    if(classList?.contains('rotate-drawer-icon')){
      classList?.remove('rotate-drawer-icon')
      classList?.add('rotate-drawer-icon-toggle');
    }

    else {
      classList?.remove('rotate-drawer-icon-toggle')
      classList?.add('rotate-drawer-icon')
    }
  }

  onSendMessage(){
    this.messages.unshift({sent: true, message: this.messageController.value});
    this.messages.unshift({sent: false, message: this.chatService.postMessage(this.messageController.value).pipe(map(element => element.res))});
    this.messageController.reset();
  }

  isArrayElementObservable(element: any){
    return isObservable(element);
  }
  
}
