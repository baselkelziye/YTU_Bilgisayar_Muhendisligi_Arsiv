import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ChatbotSettingsComponent } from './chatbot-settings.component';

describe('ChatbotSettingsComponent', () => {
  let component: ChatbotSettingsComponent;
  let fixture: ComponentFixture<ChatbotSettingsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ChatbotSettingsComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ChatbotSettingsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
