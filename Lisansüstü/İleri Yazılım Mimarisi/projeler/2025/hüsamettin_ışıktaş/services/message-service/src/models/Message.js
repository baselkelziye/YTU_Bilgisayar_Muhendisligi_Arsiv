const mongoose = require('mongoose');

const messageSchema = new mongoose.Schema({
  chatId: {
    type: String,
    required: true,
    index: true,
  },
  senderId: {
    type: String,
    required: true,
    index: true,
  },
  content: {
    type: String,
    required: function() {
      return this.messageType === 'TEXT';
    },
    maxlength: 5000,
  },
  messageType: {
    type: String,
    enum: ['TEXT', 'FILE', 'IMAGE', 'VIDEO'],
    default: 'TEXT',
  },
  fileUrl: {
    type: String,
    required: function() {
      return ['FILE', 'IMAGE', 'VIDEO'].includes(this.messageType);
    },
  },
  status: {
    type: String,
    enum: ['SENT', 'DELIVERED', 'READ', 'DELETED'],
    default: 'SENT',
  },
  deleted: {
    type: Boolean,
    default: false,
  },
}, {
  timestamps: true,
});

messageSchema.index({ chatId: 1, createdAt: -1 });
messageSchema.index({ senderId: 1, createdAt: -1 });

const Message = mongoose.model('Message', messageSchema);

module.exports = Message;

