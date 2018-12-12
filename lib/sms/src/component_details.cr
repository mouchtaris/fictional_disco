# vim: et ts=2 sw=2

module ComponentDetails
  @mod_name : String
  @comp_name : String
  include SourceDetails
  include ConfDirViews
  include Sagas

  def mod_name
    @mod_name
  end

  def comp_name
    @comp_name
  end

  def include_saga_in(scope)
    conf_comp_includes(mod_name, comp_name, scope)
      .map { |incl| saga_include_header incl } +
      conf_comp_includes(mod_name, comp_name, :system, scope)
        .map { |incl| saga_include_system_header incl }
  end
end
