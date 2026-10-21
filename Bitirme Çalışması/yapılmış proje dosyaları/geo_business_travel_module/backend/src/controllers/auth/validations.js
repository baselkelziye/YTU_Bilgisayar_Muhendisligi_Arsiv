import Joi from 'joi';

const RegisterSchema = Joi.object({
  name: Joi.string().required(),
  surname: Joi.string().required(),
  email: Joi.string().email().required(),
  username: Joi.string().min(5).required(),
  password: Joi.string().min(8).required(),
  role: Joi.string().required()
});

const LoginSchema = Joi.object({
  username: Joi.string().min(5).required(),
  password: Joi.string().min(8).required(),
});

export { 
  RegisterSchema, 
  LoginSchema 
};