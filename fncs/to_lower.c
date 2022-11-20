//
// Created by grafsky on 11/20/22.
//


char to_lower(char chr){
    return (chr >= 'A' && chr <= 'Z') ? (chr + ('a' - 'A')) : chr;
}