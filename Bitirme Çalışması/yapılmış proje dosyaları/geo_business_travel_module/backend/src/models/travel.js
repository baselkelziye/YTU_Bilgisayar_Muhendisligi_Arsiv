import mongoose, { Schema } from "mongoose";

const Schema = mongoose.Schema;

const TravelSchema = new Schema({
  // travelId: {
  //   type: Number,
  //   required: true,
  //   unique: true
  // },
  employeeUsername: {
    type: String,
    required: true,
  },
  travelDate: {
    type: String,
    default: Date.now.toString()
  },
  startLocation: {
    type: String,
    required: true
  },
  endLocation: {
    type: String,
    required: true
  },
  invoicePhoto: {
    type: String,
    required: true
  },
  invoiceInfo: {
    type: String,
    required: true
  },
  invoiceNote: {
    type: String,
  },
  invoicePrice: {
    type: Number,
    required: true,
  },
  priceEstimate: {
    type: Number,
    required: true
  },
  suspicious: {
    type: String,
    default: "no",
    enum: [
      "no",
      "yes",
    ]
  },
  status: {
    type: String,
    default: "waiting",
    enum: [
      "waiting",
      "approved",
      "rejected"
    ]
  },
  approveByAccountant: {
    type: String,
    // required: true,
    default: null,
  },
  approveDate: {
    type: String,
    // default: Date.now.toString()
  }
});

const Travel = mongoose.model("travel", TravelSchema);

export default Travel;