import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ChatbotMainComponent } from './chatbot-main.component';

describe('ChatbotMainComponent', () => {
  let component: ChatbotMainComponent;
  let fixture: ComponentFixture<ChatbotMainComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ChatbotMainComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ChatbotMainComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
