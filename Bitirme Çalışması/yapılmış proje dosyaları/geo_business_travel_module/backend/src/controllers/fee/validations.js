import Joi from "joi";

const FeeSchema = Joi.object({
  city: Joi.string().required(),
  openingFee: Joi.number().required(),
  feePerKm: Joi.number().required(),
  shortDistance: Joi.number().required(),
});

export default FeeSchema;