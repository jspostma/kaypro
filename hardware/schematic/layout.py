from bs4 import BeautifulSoup

layout_file = 'layout.svg'

def get_layout(fname='layout.svg'):
    with open(fname) as fd:
        soup = BeautifulSoup(fd, 'xml')
    return soup

