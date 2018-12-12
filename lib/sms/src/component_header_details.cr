# vim: et ts=2 sw=2

module ComponentHeaderDetails
  include ComponentDetails

  #@ override SourceDetails
  def path_suffix
    [
      @mod_name,
      "#{@comp_name}.h",
    ]
  end

  def include_saga
    include_saga_in :public
  end

  #@ override SourceDetails
  def file_header_saga
    saga_pragma(:once) +
      include_saga +
      saga_open_modspace(mod_name)
      saga_declare_sacl(mod_name, comp_name)
  end

  #@ override SourceDetails
  def file_footer_saga
    saga_close_modspace
  end
end
