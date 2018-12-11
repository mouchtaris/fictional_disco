# vim: et ts=2 sw=2

module ConfDirViews
  @conf : ConfDirStorage

  def conf_structure
    @conf.subconf :structure
  end

  def conf_mods
    conf_structure.list(:mods)
  end

  def conf_mod(name)
    conf_structure.subconf(:mods).list(name)
  end
end
