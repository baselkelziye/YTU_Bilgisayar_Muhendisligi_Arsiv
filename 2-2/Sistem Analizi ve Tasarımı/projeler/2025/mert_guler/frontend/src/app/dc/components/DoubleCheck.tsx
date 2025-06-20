import React from 'react';
import { Check } from 'lucide-react';

const DoubleCheck: React.FC<{ read: boolean }> = ({ read }) => (
    <span style={{ position: 'relative', display: 'inline-block', width: 16, height: 16 }}>
    <Check size={16} style={{ position: 'absolute', left: 0, top: 0, color: read ? '#4fc3f7' : '#888' }} />
    <Check size={16} style={{ position: 'absolute', left: 4, top: 0, color: read ? '#4fc3f7' : '#888' }} />
  </span>
);

export default DoubleCheck;
