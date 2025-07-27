import os
import shutil
import subprocess
import traceback
from pathlib import Path
from loguru import logger

class FileSystemManager:
    @staticmethod
    def create_default_folders() -> None:
        logger.success("Starting the process of creating default directories")
        default_folders = [
            ".config", "Desktop", "Downloads", "Templates", "Public",
            "Documents", "Music", "Pictures", "Videos"
        ]
        expanded_folders = [str(Path.home() / folder) for folder in default_folders]
        try:
            subprocess.run(["mkdir", "-p", *expanded_folders], check=True)
        except Exception:
            logger.error(f"Error creating default directories: {traceback.format_exc()}")
        logger.success("The process of creating default directories is complete!")

    @staticmethod
    def copy_with_exclusions(src: Path, dst: Path, exclusions: list) -> None:
        os.makedirs(dst, exist_ok=True)
        for item in os.listdir(src):
            item_path = os.path.join(src, item)
            if item in exclusions:
                continue
            dest_path = os.path.join(dst, item)
            if os.path.isdir(item_path):
                FileSystemManager.copy_with_exclusions(
                    src=Path(item_path),
                    dst=Path(dest_path),
                    exclusions=exclusions
                )
            else:
                if os.path.exists(dest_path):
                    logger.info(f"Backing up existing file: {dest_path}")
                    os.rename(dest_path, f"{dest_path}.bak")
                os.symlink(item_path, dest_path)
                logger.success(f"Symlinked {item_path} to {dest_path}")

    @staticmethod
    def make_backup(dst: Path = Path("./backup")) -> None:
        os.makedirs(dst, exist_ok=True)
        home = Path.home()
        config_path = home / ".config"
        bin_path = home / "bin"
        nemo_path = home / ".local" / "share" / "nemo"
        bashrc_path = home / ".bashrc"
        env_path = home / ".env"
        xresources_path = home / ".Xresources"
        xinitrc_path = home / ".xinitrc"
        index_theme_path = home / ".icons" / "default" / "index.theme"

        if config_path.exists():
            logger.info("Starting to back up the \".config\" folder.")
            try:
                shutil.copytree(src=config_path, dst=dst / ".config", dirs_exist_ok=True)
                logger.success("Successfully backed up the \".config\" folder")
            except Exception:
                logger.error(f"An error occurred during copying: {traceback.format_exc()}")

        if bin_path.exists():
            logger.info("Starting to back up the \"bin\" folder.")
            try:
                shutil.copytree(src=bin_path, dst=dst / "bin", dirs_exist_ok=True)
                logger.success("Successfully backed up the \"bin\" folder")
            except Exception:
                logger.error(f"An error occurred during copying: {traceback.format_exc()}")

        if nemo_path.exists():
            logger.info("Starting to back up the \".local/share/nemo\" folder.")
            try:
                nemo_dest = dst / ".local" / "share" / "nemo"
                nemo_dest.mkdir(parents=True, exist_ok=True)
                shutil.copytree(src=nemo_path, dst=nemo_dest, dirs_exist_ok=True)
                logger.success("Successfully backed up the \".local/share/nemo\" folder")
            except Exception:
                logger.error(f"An error occurred during copying: {traceback.format_exc()}")

        if bashrc_path.exists():
            logger.info("Starting to back up the \".bashrc\" file.")
            try:
                shutil.copy(src=bashrc_path, dst=dst / ".bashrc")
                logger.success("Successfully backed up the \".bashrc\" file")
            except Exception:
                logger.error(f"An error occurred during copying: {traceback.format_exc()}")

        if env_path.exists():
            logger.info("Starting to back up the \".env\" file.")
            try:
                shutil.copy(src=env_path, dst=dst / ".env")
                logger.success("Successfully backed up the \".env\" file")
            except Exception:
                logger.error(f"An error occurred during copying: {traceback.format_exc()}")

        if xresources_path.exists():
            logger.info("Starting to back up the \".Xresources\" file.")
            try:
                shutil.copy(src=xresources_path, dst=dst / ".Xresources")
                logger.success("Successfully backed up the \".Xresources\" file")
            except Exception:
                logger.error(f"An error occurred during copying: {traceback.format_exc()}")

        if xinitrc_path.exists():
            logger.info("Starting to back up the \".xinitrc\" file.")
            try:
                shutil.copy(src=xinitrc_path, dst=dst / ".xinitrc")
                logger.success("Successfully backed up the \".xinitrc\" file")
            except Exception:
                logger.error(f"An error occurred during copying: {traceback.format_exc()}")

        if index_theme_path.exists():
            logger.info("Starting to back up the \".icons/default/index.theme\" file.")
            try:
                dest = dst / ".icons" / "default" / "index.theme"
                dest.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy(src=index_theme_path, dst=dest)
                logger.success("Successfully backed up the \".icons/default/index.theme\" file")
            except Exception:
                logger.error(f"An error occurred during copying: {traceback.format_exc()}")

    @staticmethod
    def copy_dotfiles(exclude_bspwm: bool, exclude_hyprland: bool, configs_dir: str = "configs") -> None:
        logger.success("Starting the process of copying dotfiles")
        home = Path.home()
        config_folders_exclusions = []
        if exclude_bspwm:
            config_folders_exclusions.extend(["bspwm", "polybar"])
        if exclude_hyprland:
            config_folders_exclusions.extend(["hypr", "swaylock", "waybar"])

        # Symlink configs/ to ~/.config/
        FileSystemManager.copy_with_exclusions(
            src=Path(configs_dir),
            dst=home / ".config",
            exclusions=config_folders_exclusions,
        )

        # Symlink other dotfiles if they exist in configs_dir
        additional_files = [
            (f"{configs_dir}/.bashrc", home / ".bashrc"),
            (f"{configs_dir}/.env", home / ".env"),
            (f"{configs_dir}/.Xresources", home / ".Xresources", not exclude_bspwm),
            (f"{configs_dir}/.xinitrc", home / ".xinitrc", not exclude_bspwm),
            (f"{configs_dir}/.icons/default/index.theme", home / ".icons" / "default" / "index.theme", True),
        ]
        for src, dst, condition in additional_files:
            src_path = Path(src)
            if condition and src_path.exists():
                if dst.exists():
                    logger.info(f"Backing up existing file: {dst}")
                    os.rename(dst, f"{dst}.bak")
                dst.parent.mkdir(parents=True, exist_ok=True)
                os.symlink(src_path, dst)
                logger.success(f"Symlinked {src_path} to {dst}")

        # Symlink bin/ if it exists
        bin_src = Path(f"{configs_dir}/bin")
        if bin_src.exists():
            bin_dst = home / "bin"
            if bin_dst.exists():
                logger.info(f"Backing up existing directory: {bin_dst}")
                shutil.move(bin_dst, f"{bin_dst}.bak")
            os.symlink(bin_src, bin_dst)
            logger.success(f"Symlinked {bin_src} to {bin_dst}")

        # Symlink .local/share/nemo/ if it exists
        nemo_src = Path(f"{configs_dir}/.local/share/nemo")
        if nemo_src.exists():
            nemo_dst = home / ".local" / "share" / "nemo"
            nemo_dst.parent.mkdir(parents=True, exist_ok=True)
            if nemo_dst.exists():
                logger.info(f"Backing up existing directory: {nemo_dst}")
                shutil.move(nemo_dst, f"{nemo_dst}.bak")
            os.symlink(nemo_src, nemo_dst)
            logger.success(f"Symlinked {nemo_src} to {nemo_dst}")

        # Set permissions
        for path in [home / ".config", home / "bin"]:
            if path.exists():
                try:
                    subprocess.run(["sudo", "chmod", "-R", "700", str(path)], check=True)
                except Exception:
                    logger.error(f"[!] Error while making {path} executable: {traceback.format_exc()}")