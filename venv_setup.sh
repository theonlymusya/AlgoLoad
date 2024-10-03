python3 -m venv .venv
. .venv/bin/activate
python3 -m pip install --upgrade pip
python3 -m pip install -r requirements.txt

# https://stackoverflow.com/questions/13967428/importerror-no-module-named-six
pip uninstall six
pip install six
