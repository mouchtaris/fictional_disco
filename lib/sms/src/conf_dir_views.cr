# vim: et ts=2 sw=2

module ConfDirViews
  @conf : ConfDirStorage

  def conf
    @conf
  end

  def conf_sms_root
    @conf.root
  end

  def conf_project_root
    @conf.value :project_root
  end

  def conf_skeletor
    @conf.subconf :skeletor
  end

  def conf_structure
    @conf.subconf :structure
  end

  def conf_mods_conf
    conf_structure.subconf(:mods)
  end

  def conf_mod(name)
    conf_mods_conf.subconf(name)
  end

  def conf_each_mod
    conf_mods_conf.list.each do |mod_name|
      yield mod_name, conf_mod(mod_name)
    end
  end

  def conf_mods
    ({} of String => ConfDirStorage).tap do |result|
      conf_each_mod do |name, mod|
        result[name] = mod
      end
    end
  end

  def conf_comps_conf(mod_name)
    conf_mod(mod_name).subconf(:comps)
  end

  def conf_comp(mod_name, comp_name)
    conf_comps_conf(mod_name).subconf(comp_name)
  end

  def conf_each_comp(mod_name)
    conf_comps_conf(mod_name).list.each do |comp_name|
      yield comp_name, conf_comp(mod_name, comp_name)
    end
  end

  def conf_comps(mod_name)
    ({} of String => ConfDirStorage).tap do |result|
      conf_each_comp(mod_name) do |name, comp|
        result[name] = comp
      end
    end
  end

  def conf_comp_includes(mod_name, comp_name, *opts)
    opts_suff = opts.join("_")
    conf_comp(mod_name, comp_name).lines("include_#{opts_suff}")
  end
end
