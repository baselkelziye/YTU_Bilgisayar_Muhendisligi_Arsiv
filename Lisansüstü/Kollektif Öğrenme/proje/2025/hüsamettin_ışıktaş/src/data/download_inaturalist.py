"""
Download script for iNaturalist 2021 dataset (Mini Train + Val).
Downloads dataset and saves to local directory.
"""

import os
import hashlib
import tarfile
import requests
from tqdm import tqdm

# Expected MD5 checksums from the competition page
EXPECTED_CHECKSUMS = {
    'train_mini.tar.gz': 'db6ed8330e634445efc8fec83ae81442',
    'train_mini.json.tar.gz': '395a35be3651d86dc3b0d365b8ea5f92',  # Fixed checksum
    'val.tar.gz': 'f6f6e0e242e3d4c9569ba56400938afc',
    'val.json.tar.gz': '4d761e0f6a86cc63e8f7afc91f6a8f0b',
}

# AWS S3 URLs
BASE_URL = "https://ml-inat-competition-datasets.s3.amazonaws.com/2021/"

def calculate_md5(file_path):
    """Calculate MD5 checksum of a file."""
    hash_md5 = hashlib.md5()
    with open(file_path, "rb") as f:
        for chunk in iter(lambda: f.read(4096), b""):
            hash_md5.update(chunk)
    return hash_md5.hexdigest()


def verify_checksum(file_path, expected_checksum):
    """Verify file checksum."""
    print(f"Verifying checksum for {os.path.basename(file_path)}...")
    actual_checksum = calculate_md5(file_path)
    if actual_checksum == expected_checksum:
        print(f"✓ Checksum verified: {actual_checksum}")
        return True
    else:
        print(f"✗ Checksum mismatch!")
        print(f"  Expected: {expected_checksum}")
        print(f"  Actual:   {actual_checksum}")
        return False


def download_file(url, output_path, expected_checksum=None):
    """Download a file with progress bar and verify checksum."""
    filename = os.path.basename(output_path)
    
    if os.path.exists(output_path):
        print(f"{filename} already exists. Checking checksum...")
        if expected_checksum and verify_checksum(output_path, expected_checksum):
            print(f"✓ {filename} is valid, skipping download")
            return True
        else:
            print(f"✗ {filename} is corrupted, re-downloading...")
            os.remove(output_path)
    
    print(f"\nDownloading {filename}...")
    print(f"URL: {url}")
    
    try:
        # Get file size for progress bar
        response = requests.head(url, allow_redirects=True)
        total_size = int(response.headers.get('content-length', 0))
        
        # Check if we can resume download
        resume_pos = 0
        if os.path.exists(output_path + '.part'):
            resume_pos = os.path.getsize(output_path + '.part')
            if resume_pos > 0:
                print(f"Resuming download from {resume_pos:,} bytes...")
        
        # Download with progress bar
        headers = {}
        if resume_pos > 0:
            headers['Range'] = f'bytes={resume_pos}-'
        
        response = requests.get(url, headers=headers, stream=True, allow_redirects=True)
        
        # Update total size if resuming
        if resume_pos > 0 and 'content-range' in response.headers:
            content_range = response.headers['content-range']
            total_size = int(content_range.split('/')[-1])
        
        mode = 'ab' if resume_pos > 0 else 'wb'
        temp_path = output_path + '.part'
        
        with open(temp_path, mode) as f:
            with tqdm(total=total_size, initial=resume_pos, unit='B', 
                     unit_scale=True, unit_divisor=1024, desc=filename) as pbar:
                for chunk in response.iter_content(chunk_size=8192):
                    if chunk:
                        f.write(chunk)
                        pbar.update(len(chunk))
        
        # Move temp file to final location
        os.rename(temp_path, output_path)
        print(f"✓ Download completed: {filename}")
        
        # Verify checksum if provided
        if expected_checksum:
            return verify_checksum(output_path, expected_checksum)
        return True
        
    except requests.exceptions.RequestException as e:
        print(f"✗ Download failed: {e}")
        # Clean up partial download
        if os.path.exists(output_path + '.part'):
            os.remove(output_path + '.part')
        return False
    except Exception as e:
        print(f"✗ Error during download: {e}")
        # Clean up partial download
        if os.path.exists(output_path + '.part'):
            os.remove(output_path + '.part')
        return False


def extract_tar(file_path, extract_dir):
    """Extract tar.gz file with progress."""
    filename = os.path.basename(file_path)
    print(f"Extracting {filename}...")
    
    try:
        with tarfile.open(file_path, 'r:gz') as tar:
            # Get total members for progress
            members = tar.getmembers()
            total = len(members)
            
            for member in tqdm(members, desc=f"Extracting {filename}", unit="files"):
                tar.extract(member, extract_dir)
        
        print(f"✓ Extraction completed: {filename}")
        return True
    except Exception as e:
        print(f"✗ Extraction failed: {e}")
        return False


def download_inaturalist_2021(dataset_dir="dataset/inaturalist_2021"):
    """
    Download iNaturalist 2021 dataset (Mini Train + Val) to local directory.
    
    Args:
        dataset_dir: Directory to save dataset (tar files and extracted)
    """
    
    # Create directories
    os.makedirs(dataset_dir, exist_ok=True)
    download_dir = os.path.join(dataset_dir, "downloads")
    extract_dir = dataset_dir
    os.makedirs(download_dir, exist_ok=True)
    
    # Files to download (Only Train Mini and Val)
    files_to_download = [
        'train_mini.tar.gz',
        'train_mini.json.tar.gz',
        'val.tar.gz',
        'val.json.tar.gz'
    ]
    
    print(f"Files to download: {files_to_download}")
    print(f"Download directory: {download_dir}")
    print(f"Extract directory: {extract_dir}")
    
    # Download files
    downloaded_files = []
    for filename in files_to_download:
        url = BASE_URL + filename
        output_path = os.path.join(download_dir, filename)
        expected_checksum = EXPECTED_CHECKSUMS.get(filename)
        
        # Check if already downloaded
        if os.path.exists(output_path):
            print(f"{filename} already exists. Checking checksum...")
            if expected_checksum and verify_checksum(output_path, expected_checksum):
                print(f"✓ {filename} is valid, skipping download")
                downloaded_files.append(output_path)
                continue
            else:
                print(f"✗ {filename} is corrupted, re-downloading...")
                os.remove(output_path)
        
        print(f"\nDownloading {filename}...")
        print(f"URL: {url}")
        print(f"Destination: {output_path}")
        
        if download_file(url, output_path, expected_checksum):
            downloaded_files.append(output_path)
        else:
            print(f"Failed to download {filename}")
            return False
    
    print("\n" + "="*50)
    print("All downloads completed successfully!")
    print("="*50 + "\n")
    
    # Extract files
    print("Extracting files...")
    for file_path in downloaded_files:
        if file_path.endswith('.tar.gz'):
            if not extract_tar(file_path, extract_dir):
                print(f"Failed to extract {file_path}")
                return False
    
    print("\n" + "="*50)
    print("All extractions completed successfully!")
    print("="*50 + "\n")
    
    # Verify extracted structure
    print("Verifying extracted structure...")
    required_dirs = ['train_mini', 'val']
    
    for dir_name in required_dirs:
        dir_path = os.path.join(extract_dir, dir_name)
        if not os.path.exists(dir_path):
            print(f"✗ Missing directory: {dir_path}")
            return False
        print(f"✓ Found directory: {dir_name}")
    
    # Check for JSON files
    json_files = ['train_mini.json', 'val.json']
    
    for json_file in json_files:
        json_path = os.path.join(extract_dir, json_file)
        if not os.path.exists(json_path):
            print(f"✗ Missing JSON file: {json_path}")
            return False
        print(f"✓ Found JSON file: {json_file}")
    
    print("\n" + "="*50)
    print("Dataset download and setup completed!")
    print("="*50)
    print(f"\nDataset location: {extract_dir}")
    print(f"Tar files location: {download_dir}")
    print("\nYou can now use this dataset with iNaturalist2021Dataset class.")
    print(f"Use dataset_dir='{extract_dir}' when creating the dataset.")
    
    return True


if __name__ == "__main__":
    import argparse
    
    parser = argparse.ArgumentParser(description="Download iNaturalist 2021 dataset (Mini Train + Val)")
    parser.add_argument("--dataset_dir", default="dataset/inaturalist_2021",
                       help="Directory to save dataset (tar files and extracted)")
    
    args = parser.parse_args()
    
    download_inaturalist_2021(dataset_dir=args.dataset_dir)
