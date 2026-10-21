import mongoose, { Schema } from "mongoose";

const Schema = mongoose.Schema;

const PlanSchema = new Schema({
  _id: {
    type: mongoose.Types.ObjectId,
    default: () => new mongoose.Types.ObjectId(),
  },
  employeeUsername: {
    type: String,
    required: true,
  },
  travelDate: {
    type: String,
    required: true,
    default: Date.now.toString()
  },
  endLocation: {
    type: String,
    required: true
  },
  coordinates: {
    type: Object,
    required: true,
    lat: {
      type: String
    },
    long: {
      type: String
    }
  },
  accountantUsername: {
    type: String,
    required: true,
  },
});

const Plan = mongoose.model("plan", PlanSchema);

export default Plan;