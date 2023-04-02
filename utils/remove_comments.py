import re
def remove_comments(content):
    # Remove single-line comments
    content = re.sub(r"//.*", "", content)
    # Remove multi-line comments
    content = re.sub(r"/\*.*?\*/", "", content, flags=re.DOTALL)
    # Remove blank lines left by removing comments
    content = "\n".join([line for line in content.split("\n") if line.strip() != ""])

    return content