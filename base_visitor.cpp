#include <tree_sitter/api.h>
#include <string>
#include <iostream>

extern "C"
{
  const TSLanguage *tree_sitter_javascript(void);
}

void base_ast(TSNode &node, const std::string &source, int d)
{
    if (ts_node_child_count(node) == 0)
    {
        int start = ts_node_start_byte(node);
        int end = ts_node_end_byte(node);
        std::string token = source.substr(start, end - start);

        std::cout << std::string(d, '\t') << token << std::endl;
    }

    for (uint32_t i = 0; i < ts_node_named_child_count(node); i++)
    {
        TSNode child = ts_node_named_child(node, i);

        // std::string extra = ts_node_is_named(child) ? "#" : "";
        std::cout << std::string(d, '\t') << ts_node_type(child) << std::endl;
        base_ast(child, source, d + 1);
    }
}

void base_ast(const std::string & source)
{

    // Create a parser.
    TSParser *parser = ts_parser_new();

    // Set the parser's language (JSON in this case).
    ts_parser_set_language(parser, tree_sitter_javascript());

    // Build a syntax tree based on source code stored in a string.
    TSTree *tree = ts_parser_parse_string(parser, NULL, source.c_str(), source.size());
    TSNode root_node = ts_tree_root_node(tree);
    base_ast(root_node, source, 0);

    ts_tree_delete(tree);
    ts_parser_delete(parser);
}