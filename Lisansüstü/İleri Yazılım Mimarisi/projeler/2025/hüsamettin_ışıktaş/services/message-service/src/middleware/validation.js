const Joi = require('joi');

const sendMessageSchema = Joi.object({
  chatId: Joi.string().required(),
  content: Joi.string().max(5000).when('messageType', {
    is: 'TEXT',
    then: Joi.required(),
    otherwise: Joi.optional(),
  }),
  messageType: Joi.string().valid('TEXT', 'FILE', 'IMAGE', 'VIDEO').default('TEXT'),
  fileUrl: Joi.string().uri().when('messageType', {
    is: Joi.string().valid('FILE', 'IMAGE', 'VIDEO'),
    then: Joi.required(),
    otherwise: Joi.optional(),
  }),
});

const validate = (schema) => {
  return (req, res, next) => {
    const { error } = schema.validate(req.body);
    if (error) {
      return res.status(400).json({
        success: false,
        message: 'Validation error',
        errors: error.details.map(detail => detail.message),
      });
    }
    next();
  };
};

module.exports = {
  validateSendMessage: validate(sendMessageSchema),
};

