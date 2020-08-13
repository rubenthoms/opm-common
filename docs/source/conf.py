# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# http://www.sphinx-doc.org/en/master/config

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
import os
import sys
import opm
sys.path.insert(0, os.path.abspath("."))
#sys.path.insert(1, os.path.abspath(os.path.join(os.path.dirname(opm.__file__), "..")))
if 'VIRTUAL_ENV' in os.environ:
    site_packages_glob = os.sep.join([
        os.environ['VIRTUAL_ENV'],
        'lib', 'python3.7', 'site-packages', 'opm-*py3.7.egg'])
    site_packages = glob.glob(site_packages_glob)[-1]
    sys.path.insert(0, site_packages)


# -- Project information -----------------------------------------------------

project = 'OPM'
copyright = '2020, Ceetron Solutions AS'
author = 'Ceetron Solutions AS'

# The full version, including alpha/beta/rc tags
release = '2020.04'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx.ext.autodoc', 'sphinx.ext.coverage', 'sphinx.ext.napoleon', 'm2r'
]

master_doc = 'index'

napoleon_google_docstring = True

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['build/*']


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = "sphinx_rtd_theme"

html_theme_options = {
    'style_nav_header_background': '#000000',
}
smartquotes=False

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']


# -- Extension configuration -------------------------------------------------