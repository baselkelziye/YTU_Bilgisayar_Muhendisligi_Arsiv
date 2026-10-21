import Joi from 'joi';

const PlanSchema = Joi.object({
  planId: Joi.string(),
  employeeUsername: Joi.string().min(5),
  travelDate: Joi.string().required(),
  endLocation: Joi.string().required(),
  coordinates: Joi.object().required(),
  accountantUsername: Joi.string().required(),
});

export default PlanSchema;
