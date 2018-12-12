# vim: et ts=2 sw=2

module ModMainSourceDetails
  include SourceDetails  # polymorphic inheritance
  @mod_name: String

  #@ override SourceDetails
  def path_suffix
    [
      "#{@mod_name}.cpp",
    ]
  end

  #@ override SourceDetails
  def file_header_saga
    saga_include_header(@mod_name) +
      saga_include_header("sacl") +
      saga_empty_line +
      saga_sacl_definition_opening(@mod_name, "sacl_mod") +
      saga_indent(1) {
        saga_template_function_call(
          "sacls",
          ["#{@mod_name.upcase}__SACLS"]
        )
      } +
      saga_close_body +
      saga_open_modspace(@mod_name)
  end

  #@ override SourceDetails
  def file_footer_saga
    saga_close_modspace
  end
end
