TISSUE LAYERS SECTION SEGMENTATION

This project tends to create a model using U-Net architecture for the auto segment of
the epidermis regions in WSI images The Cancer Genome Atlas (TCGA) Repository. In
the preprocessing step, we will carefully select 50 whole slide images(WSIs) and we
have to do annotations, masks, and patches for each slide before implementing the
U-Net model.



Tools:
  Sedeen Viewer : to view and annotate WSI slides 

  VSCode / google colab / Keggle : to run python scripts

  libvips : image processing engine, enables the user to work on big image without loading it entirely to the RAM


The project workflow for code scripts:

  1- to extract mask images from XML files use create_masks.ipynb
  
  2- to split the WSI images or ROI images with correspond masks use the patch_script.ipynb
  
  3- to train u-net/ VGG-Unet/ Res-Unet/ Linknet(Pytorch) models use the notebooks in folder models_training_notebooks
  
  4- to test the slides or ROIs use the slide_test_final.ipynb
  
  5- to apply postprocessing operations use postprocessing.ipynb
