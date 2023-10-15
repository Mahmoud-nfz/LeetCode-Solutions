def replace_between_tags(input_str, replacement_str, start_tag, end_tag):
    start_index = input_str.find(start_tag)
    end_index = input_str.find(end_tag)

    if start_index != -1 and end_index != -1 and start_index < end_index:
        before_section = input_str[:start_index] + start_tag
        after_section = end_tag + input_str[end_index + len(end_tag):]
        return before_section + replacement_str + after_section
    else:
        return input_str