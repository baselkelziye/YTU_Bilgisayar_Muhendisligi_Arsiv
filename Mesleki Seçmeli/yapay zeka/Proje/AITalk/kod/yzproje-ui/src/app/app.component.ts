import { Component, OnInit } from '@angular/core';
import {Title} from "@angular/platform-browser";

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements OnInit{
  title = 'TechTalk';

  constructor(private titleService: Title){}

  ngOnInit(){
    this.titleService.setTitle("TechTalk");
    localStorage.setItem("model", "prepared");
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

}
