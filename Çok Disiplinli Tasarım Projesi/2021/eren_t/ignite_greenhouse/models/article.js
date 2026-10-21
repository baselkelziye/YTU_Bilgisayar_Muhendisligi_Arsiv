const mongoose = require("mongoose");
const marked = require("marked");
const slugify = require("slugify");
const createDomPurify = require("dompurify");
const { JSDOM } = require("jsdom");
const dompurify = createDomPurify(new JSDOM().window);

const greenHouseSchema = new mongoose.Schema({
  greenHouseName: {
    type: String,
    required: true,
  },
  targetTemperature: {
    type: Number,
    required: true,
  },
  currentTemperature: {
    type: Number,
    required: true,
    default: 0,
  },
  slug: {
    type: String,
    required: true,
    unique: true,
  },
});

greenHouseSchema.pre("validate", function (next) {
  if (this.greenHouseName) {
    this.slug = slugify(this.greenHouseName, { lower: true, strict: true });
  }

  next();
});

module.exports = mongoose.model("Greenhouse", greenHouseSchema);
