const mongoose = require('mongoose');

const chatParticipantSchema = new mongoose.Schema({
  userId: {
    type: String,
    required: true,
  },
  role: {
    type: String,
    enum: ['MEMBER', 'ADMIN'],
    default: 'MEMBER',
  },
  joinedAt: {
    type: Date,
    default: Date.now,
  },
}, { _id: false });

const chatSchema = new mongoose.Schema({
  type: {
    type: String,
    enum: ['DIRECT', 'GROUP'],
    required: true,
  },
  name: {
    type: String,
    required: function() {
      return this.type === 'GROUP';
    },
  },
  createdBy: {
    type: String,
    required: true,
  },
  participants: [chatParticipantSchema],
}, {
  timestamps: true,
});

chatSchema.index({ 'participants.userId': 1 });
chatSchema.index({ type: 1, 'participants.userId': 1 });

const Chat = mongoose.model('Chat', chatSchema);

module.exports = Chat;

