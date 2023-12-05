import { TestBed } from '@angular/core/testing';

import { GoogletranslateService } from './googletranslate.service';

describe('GoogletranslateService', () => {
  let service: GoogletranslateService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(GoogletranslateService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
