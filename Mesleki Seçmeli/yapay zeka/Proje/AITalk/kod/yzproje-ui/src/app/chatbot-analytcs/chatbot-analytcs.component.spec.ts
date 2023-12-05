import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ChatbotAnalytcsComponent } from './chatbot-analytcs.component';

describe('ChatbotAnalytcsComponent', () => {
  let component: ChatbotAnalytcsComponent;
  let fixture: ComponentFixture<ChatbotAnalytcsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ChatbotAnalytcsComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ChatbotAnalytcsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
