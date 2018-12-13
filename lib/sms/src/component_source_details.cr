# vim: et ts=2 sw=2

module ComponentSourceDetails
  include ComponentDetails

  #@ override SourceDetails
  def path_suffix
    [
      @mod_name,
      "#{@comp_name}.cpp",
    ]
  end

  def include_saga
    include_saga_in :private
  end

  #@ override SourceDetails
  def file_header_saga
      saga_include_header("#{comp_name}.h") +
      saga_include_header("sacl.h") +
      saga_empty_line +
      saga_define_sacl(mod_name, comp_name) +
      saga_open_modspace(mod_name)
  end

  #@ override SourceDetails
  def file_footer_saga
      saga_close_modspace
  end
end
