# vim: et ts=2 sw=2

module ModMainHeaderDetails
  include ModMainDetails

  #@ override SourceDetails
  def path_suffix
    [
      "#{mod_name}.h",
    ]
  end

  def include_saga
    conf_comps(mod_name)
      .flat_map { |comp_name, _comp| saga_include_header "#{mod_name}/#{comp_name}.h" }
  end

  #@ override SourceDetails
  def file_header_saga
    saga_pragma(:once) +
      include_saga +
      saga_open_modspace(mod_name) +
      saga_indent(1) {
        saga_declare_sacl(mod_name, "sacl_mod")
      }
  end

  #@ override SourceDetails
  def file_footer_saga
    saga_close_modspace
  end
end
