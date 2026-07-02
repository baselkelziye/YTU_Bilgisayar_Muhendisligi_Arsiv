import kagglehub
import os
import shutil

def download_cub(dataset_dir="dataset"):
    """
    Downloads CUB-200-2011 dataset using kagglehub and links it to dataset/CUB_200_2011.
    """
    print("Downloading dataset via kagglehub...")
    try:
        # Download latest version
        path = kagglehub.dataset_download("wenewone/cub2002011")
        print("Path to dataset files:", path)
    except Exception as e:
        print(f"Error downloading dataset: {e}")
        print("Ensure you have set up Kaggle credentials if required.")
        return

    # Ensure dataset directory exists
    os.makedirs(dataset_dir, exist_ok=True)
    
    target_link = os.path.join(dataset_dir, "CUB_200_2011")
    
    # Remove existing link if it exists
    if os.path.islink(target_link):
        os.unlink(target_link)
    elif os.path.exists(target_link):
         print(f"Directory {target_link} already exists. Skipping link creation. Remove it if you want to re-link.")
         return
    
    # Determine the correct source path
    # Check if the downloaded path contains CUB_200_2011 or IS it.
    # The dataset usually has structure: path/CUB_200_2011/... or path/...
    
    if os.path.exists(os.path.join(path, "CUB_200_2011")):
        source_path = os.path.join(path, "CUB_200_2011")
    else:
        # Check for characteristic files to verify it's the root
        if os.path.exists(os.path.join(path, "images.txt")):
            source_path = path
        else:
            # Just link whatever we got, maybe it's inside another folder?
            # For now assume path is correct or contains it.
            source_path = path
        
    print(f"Linking {source_path} to {target_link}")
    try:
        os.symlink(source_path, target_link)
        print("Symlink created successfully.")
    except OSError as e:
        print(f"Failed to create symlink: {e}")
        print(f"Please manually copy or link: {source_path} -> {target_link}")

if __name__ == "__main__":
    download_cub()
